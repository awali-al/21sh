/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   his_nav.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 01:29:39 by aminewalial       #+#    #+#             */
/*   Updated: 2020/02/15 23:29:59 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static void	prev_line(t_hist **his, t_line *line)
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

static void	next_line(t_hist **his, t_line *line)
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

int			his_nav(t_hist **his, t_line *line)
{
	if (line->buf == UPAR)
		prev_line(his, line);
	else if (line->buf == DOWN)
		next_line(his, line);
	else
		return (0);
	return (1);
}
