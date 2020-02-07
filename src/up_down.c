/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 01:29:39 by aminewalial       #+#    #+#             */
/*   Updated: 2020/02/07 23:13:19 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void	prev_line(t_hist **his, t_line *line)
{
	if (*his)
	{
		home(line);
		if (!line->tmp)
			line->tmp = line->str;
		else if ((*his)->prv)
			*his = (*his)->prv;
		line->str = (*his)->cmd;
		put_in_pos(line->str);
		end(line);
	}
}

void	next_line(t_hist **his, t_line *line)
{
	if (line->tmp)
	{
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
		home(line);
		put_in_pos(line->str);
		end(line);
	}
}
