/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:41:17 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/08 23:39:03 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

int		curow(void)
{
	char	**arr;
	char	buf[5];
	int		ret;

	write(1, "\033[6n", 4);
	read(0, &buf, 4);
	buf[4] = '\0';
	arr = ft_strsplit(buf, ';');
	ret = ft_atoi(arr[0]);
	free_2d(&arr);
	return (ret);
}

void	go_right(t_line *line)
{
	int		l;

	l = ft_strlen(line->str) + line->prm;
	line->curs++;
	if ((line->curs + line->prm) % line->col == 0)
	{
		if (line->row != curow())
			tputs(tgetstr("do", NULL), 1, to_putchar);
		else if (line->row != curow() && line->curs != l
				&& l % line->col == 0)
			tputs(tgetstr("up", NULL), 1, to_putchar);
		tputs(tgetstr("cr", NULL), 1, to_putchar);
	}
	else
		tputs(tgetstr("nd", NULL), 1, to_putchar);
}

void	go_left(t_line *line)
{
	if (((line->curs + line->prm) % line->col) == 0)
	{
		tputs(tgetstr("up", NULL), 1, to_putchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, line->col - 1), 1, to_putchar);
	}
	else
		tputs(tgetstr("le", NULL), 1, to_putchar);
	line->curs--;
}
