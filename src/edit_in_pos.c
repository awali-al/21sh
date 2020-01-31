/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_in_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:56:41 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/01 00:22:04 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void	put_in_pos(char *str)
{
	tputs(tgetstr("sc", NULL), 1, to_putchar);
	tputs(tgetstr("cd", NULL), 1, to_putchar);
	ft_putstr(str);
	tputs(tgetstr("rc", NULL), 1, to_putchar);
}

void	add_in_pos(char **str, char b, int *curs)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(ft_strlen(*str) + 1);
	while (i < *curs)
	{
		tmp[i] = (*str)[i];
		i++;
	}
	tmp[i] = b;
	i++;
	while (i < ft_strlen((*str)) + 1)
	{
		tmp[i] = (*str)[i - 1];
		i++;
	}
	ft_strdel(str);
	(*str) = tmp;
	put_in_pos(*str + *curs);
	go_right(curs, 1);
}

void	del_in_pos(char **str, int *curs)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	go_left(curs, 1);
	tmp = ft_strnew(ft_strlen(*str) - 1);
	while ((*str)[i])
	{
		if (i != *curs)
		{
			tmp[j] = (*str)[i];
			j++;
		}
		i++;
	}
	ft_strdel(str);
	*str = tmp;
	put_in_pos(*str + *curs);
}
