/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_in_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:56:41 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/07 22:58:27 by awali-al         ###   ########.fr       */
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

void	add_in_pos(t_line *line)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = ft_strnew(ft_strlen(line->str) + 1);
	while (i < (size_t)line->curs)
	{
		tmp[i] = line->str[i];
		i++;
	}
	tmp[i] = line->buf;
	i++;
	while (i < ft_strlen((line->str)) + 1)
	{
		tmp[i] = line->str[i - 1];
		i++;
	}
	ft_strdel(&(line->str));
	line->str = tmp;
	put_in_pos(line->str + line->curs);
	go_right(line);
}

void	del_in_pos(t_line *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	go_left(line);
	tmp = ft_strnew(ft_strlen(line->str) - 1);
	while (line->str[i])
	{
		if (i != line->curs)
		{
			tmp[j] = line->str[i];
			j++;
		}
		i++;
	}
	ft_strdel(&(line->str));
	line->str = tmp;
	put_in_pos(line->str + line->curs);
}
