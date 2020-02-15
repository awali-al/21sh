/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:46:50 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/15 01:30:02 by awali-al         ###   ########.fr       */
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

/*static void		store_print(t_hist **his, t_line *line)
{
	if (ft_isprint(line->buf))
		add_in_pos(line);
	else if (line->buf == BACKSPACE && line->idx)
		del_in_pos(line);
	else if (line->buf == RGHT && line->idx < (int)ft_strlen(line->str))
		go_right(line);
	else if (line->buf == LEFT && line->idx)
		go_left(line);
	else if (line->buf == HOME)
		home(line);
	else if (line->buf == END)
		end(line);
	else if (line->buf == UPAR)
		prev_line(his, line);
	else if (line->buf == DOWN)
		next_line(his, line);
	else if (line->buf == '\n')
		new_line(line);
}*/

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
		// dprintf(line.fdtty, "cc: %d wc: %d cr: %d wr: %d\n", line.curp.col, line.col, line.curp.row, line.row);
		read(0, &line.buf, 12);
		if (condition(line.buf, line.con))
			break ;
		else
		{
			printf("%d\n", line.buf);
			// store_print(his, &line);
			line.con = qdq_con(line.buf, line.con);
		}
	}
	close(line.fdtty);
	ret = ft_strjoin(line.cmd, line.str);
	reset_input_mode();
	add_to_history(his, ret);
	return (ret);
}
