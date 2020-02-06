/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 01:29:39 by aminewalial       #+#    #+#             */
/*   Updated: 2020/02/06 02:02:52 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void	prev_line(t_hist **his, t_line *line)
{
	printf("salam\n");
	if (!line->tmp)
		line->tmp = line->str;
	else
		*his = (*his)->prv;
	line->str = (*his)->cmd;
	home(line);
	put_in_pos(line->str);
	end(line);
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
