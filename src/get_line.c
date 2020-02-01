/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:46:50 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/01 21:50:51 by awali-al         ###   ########.fr       */
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

static void		store_print(t_line **line)
{
	if (ft_isprint((*line)->buf))
		add_in_pos(line);
	else if ((*line)->buf == BACKSPACE && (*line)->curs)
		del_in_pos(line);
	else if ((*line)->buf == RIGHT && (*line)->curs < ft_strlen((*line)->str))
		go_right(line);
	else if ((*line)->buf == LEFT && (*line)->curs)
		go_left(line);
}

static t_line	*line_ini(int prm)
{
	struct winsize	ws;
	t_line			*ret;

	ret = (t_line*)malloc(sizeof(t_line));
	ioctl(0, TIOCGWINSZ, &ws);
	ret->str = ft_strdup("");
	ret->col = ws.ws_col;
	ret->row = ws.ws_row;
	ret->prv = NULL;
	ret->nxt = NULL;
	ret->prm = prm;
	ret->curs = 0;
	ret->con = 0;
	return (ret);
}

char			*get_line(t_line **bot, int prm)
{
	t_line			*line;

	set_input_mode();
	line = line_ini(prm);
	while (1)
	{
		line->buf = 0;
		read(0, &line->buf, 4);
		if (condition(line->buf, line->con))
			break ;
		else
		{
			store_print(&line);
			line->con = qdq_con(&line->buf, line->con);
		}
	}
	reset_input_mode();
	// add_to_history(bot, line);
	return (line->str);
}
