/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:41:17 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/16 01:44:25 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void		go_right(t_line *line)
{
	int		l;

	if (line->str[line->idx] == '\n' || line->col == line->curp.col)
	{
		cur_down(line);
		cur_begn(line);
	}
	else if (line->row != line->curp.row)
		cur_rght(line);
	else
	{
		cur_rght(line);
		if ((l = nxt_end(line)) && (line->curp.col + l) == line->col + 2)
		{
			tputs(tgetstr("sc", NULL), 1, to_putchar);
			tputs(tgetstr("do", NULL), 1, to_putchar);
			tputs(tgetstr("rc", NULL), 1, to_putchar);
		}
	}
	line->idx++;
}

void		go_left(t_line *line)
{
	line->idx--;
	if (line->curp.col > 1)
		cur_left(line);
	else
	{
		cur_upln(line);
		if (line->str[line->idx] == '\n')
			line->curp.col = prv_end(line);
		else
			line->curp.col = line->col - 1;
		tputs(tgoto(tgetstr("ch", NULL), 0, line->curp.col - 1), 1, to_putchar);
	}
}

static void	go_up(t_line *line)
{
	int		i;

	i = 1;
	while (line->idx && i++ < line->col && line->str[line->idx] != '\n')
		go_left(line);
}

static void	go_down(t_line *line)
{
	int		i;

	i = 0;
	while (line->str[line->idx] && line->str[line->idx] != '\n' &&
			i++ < line->col)
		go_right(line);
}

int			arrow_movement(t_line *line)
{
	if (line->buf == RGHT && line->idx < (int)ft_strlen(line->str))
		go_right(line);
	else if (line->buf == LEFT && line->idx)
		go_left(line);
	else if (line->buf == ALT_UPAR)
		go_up(line);
	else if (line->buf == ALT_DOWN)
		go_down(line);
	else
		return (0);
	return (1);
}
