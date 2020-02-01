/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:46:50 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/01 11:30:02 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static int	condition(int b, int c)
{
	if (b == '\004' || (!c && b == '\n'))
		return (1);
	else
		return (0);
}

static int	qdq_con(int b, int c)
{
	if (c && b != c)
		return (c);
	else if (!c && (b == '\'' || b == '\"'))
		return (b);
	else
		return (0);
}

static void	store_print(t_line *line, int pos)
{
	if (ft_isprint(line->b))
		add_in_pos(line);
	else if (line->b == BACKSPACE && line->curs)
		del_in_pos(line);
	else if (line->b == RIGHT && line->curs < ft_strlen(line->str))
		go_right(&line->curs, 1);
	else if (line->b == LEFT && line->curs)
		go_left(&line->curs, 1);
	else if (line->b == END)
		go_right(&line->curs, ft_strlen(line->str + line->curs));
	else if (line->b == HOME)
		go_left(&line->curs, line->curs);
}

char		*get_line(int pos)
{
	t_line	*line;
	int		c;

	set_input_mode();
	c = 0;
	line = (t_line*)malloc(sizeof(line));
	line->curs = 0;
	line->str = ft_strdup("");
	while (1)
	{
		line->b = 0;
		read(0, &line->b, 4);
		if (condition(line->b, c))
			break ;
		else
		{
			c = qdq_con(line->b, c);
			store_print(line, pos);
		}
	}
	reset_input_mode();
	return (line->str);
}
