/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:36:49 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/14 21:42:00 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void	home(t_line *line)
{
	while (line->idx)
	{
		dprintf(line->fdtty, "pchar: %c idx: %d cc: %d\n",line->str[line->idx - 1], line->idx, line->curp.col);
		sleep(1);
		go_left(line);
	}
}

void	end(t_line *line)
{
	int		n;

	n = ft_strlen(line->str);
	while (line->idx < n)
		go_right(line);
}
