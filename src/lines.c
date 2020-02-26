/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:29:39 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/26 23:33:13 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh_rl.h"

void	up_line(t_line *line)
{
	int		i;

	i = -2;
	while (line->idx && line->str[line->idx + 1] != '\n')
	{
		go_left(line);
		i++;
		sleep(1);
	}
	dprintf(line->fdtty, "%d\n", i);
	while ((line->idx > 0 && line->str[line->idx - 1] != '\n'))
	{
		go_left(line);
		sleep(1);
	}
	while (i-- && line->str[line->idx] != '\n')
	{
		go_right(line);
		sleep(1);
	}
}
