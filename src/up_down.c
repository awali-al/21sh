/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 01:29:39 by aminewalial       #+#    #+#             */
/*   Updated: 2020/02/14 15:32:51 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void	prev_line(t_hist **his, t_line *line)
{
	if (*his)
	{
		dprintf(line->fdtty, "idx: %d\n", line->idx);
		home(line);
		dprintf(line->fdtty, "idx: %d\n", line->idx);
		dprintf(line->fdtty, "going home cc: %d wc: %d cr: %d wr: %d\n", line->curp.col, line->col, line->curp.row, line->row);
		if (!line->tmp)
			line->tmp = line->str;
		else if ((*his)->prv)
			*his = (*his)->prv;
		line->str = (*his)->cmd;
		put_in_pos(line->str);
		end(line);
		dprintf(line->fdtty, "going to end cc: %d wc: %d cr: %d wr: %d\n", line->curp.col, line->col, line->curp.row, line->row);
	}
}

void	next_line(t_hist **his, t_line *line)
{
	if (line->tmp)
	{
		home(line);
		if ((*his)->nxt)
		{
			*his = (*his)->nxt;
			line->str = (*his)->cmd;
		}
		else
		{
			line->str = line->tmp;
			line->tmp = NULL;
		}
		put_in_pos(line->str);
		end(line);
	}
}
