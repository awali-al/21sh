/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:46:50 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/16 03:06:54 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static int		condition(int b, int c)
{
	if (b == '\004' || (!c && b == '\n'))
		return (1);
	else
		return (0);
}

static int		qdq_con(int b, int c)
{
	if (c && b != c)
		return (c);
	else if (!c && (b == '\'' || b == '\"'))
		return (b);
	else
		return (0);
}

static int		store_print(t_hist **his, t_line *line)
{
	if (edit_in_pos(line))
		return (1);
	else if (arrow_movement(line))
		return (1);
	else if (navigation(line))
		return (1);
	else if (his_nav(his, line))
		return (1);
	else if (line->buf == '\n')
	{
		new_line(line);
		return (1);
	}
	
	return (0);
}

static t_line	line_ini(int prm)
{
	struct winsize	ws;
	t_line			ret;
	char			buf[8];
	int				i;

	ret.fdtty = open("/dev/ttys003", O_WRONLY);
	ioctl(0, TIOCGWINSZ, &ws);
	tputs("\033[6n", 4, to_putchar);
	i = read(0, &buf, 7);
	buf[i] = '\0';
	ret.curp.col = ft_atoi(ft_strchr(buf, ';') + 1);
	ret.curp.row = ft_atoi(buf + 2);
	ret.cmd = ft_strnew(1);
	ret.str = ft_strnew(1);
	ret.col = ws.ws_col;
	ret.row = ws.ws_row;
	ret.tmp = NULL;
	ret.prm = prm;
	ret.idx = 0;
	ret.con = 0;
	return (ret);
}

char			*get_line(t_hist **his, int prm)
{
	t_line			line;
	char			*ret;

	set_input_mode();
	line = line_ini(prm);
	while (1)
	{
		line.buf = 0;
		read(0, &line.buf, 12);
		if (condition(line.buf, line.con))
			break ;
		else
		{
			store_print(his, &line);
			dprintf(line.fdtty, "%d %d\n", line.curp.col, line.col);
			line.con = qdq_con(line.buf, line.con);
		}
	}
	close(line.fdtty);
	ret = ft_strjoin(line.cmd, line.str);
	reset_input_mode();
	add_to_history(his, ret);
	return (ret);
}
