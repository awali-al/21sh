/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:41:17 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/31 20:52:00 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

int		to_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

void	go_right(int *curs, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		tputs(tgetstr("nd", NULL), 1, to_putchar);
		(*curs)++;
		i++;
	}
}

void	go_left(int *curs, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		tputs(tgetstr("le", NULL), 1, to_putchar);
		(*curs)--;
		i++;
	}
}
