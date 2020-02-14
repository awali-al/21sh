/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:36:49 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/14 16:11:23 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void	home(t_line *line)
{
	while (line->idx)
	{
		go_left(line);
		sleep(1);
	}
}

void	end(t_line *line)
{
	int		n;

	n = ft_strlen(line->str);
	while (line->idx < n)
		go_right(line);
}
