/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:36:49 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/12 22:08:53 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void	home(t_line *line)
{
	int		i;

	i = line->idx;
	while (i >= 0)
	{
		go_left(line);
		i--;
	}
}

void	end(t_line *line)
{
	int		n;
	int		i;

	i = 0;
	n = ft_strlen(line->str);
	while (i < n)
	{
		go_right(line);
		i++;
	}
}
