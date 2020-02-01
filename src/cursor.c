/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:41:17 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/01 12:32:56 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

int		to_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

t_pos	get_curs(void)
{
	char			**arr;
	char			buf[5];
	t_pos			ret;

	write(1, "\033[6n", 4);
	read(0, &buf, 4);
	buf[4] = '\0';
	arr = ft_strsplit(buf, ';');
	ret.row = ft_atoi(arr[0]);
	ret.col = ft_atoi(arr[1]);
	free_2d(&arr);
	return (ret);
}

void	go_right(int *curs, int n)
{
	struct winsize	ws;
	t_pos			cp;
	int				i;

	i = 0;
	ioctl(0, TIOCGWINSZ, &ws);
	cp = get_curs();
	while (i < n)
	{
		if (*curs < ws.ws_col)
			tputs(tgetstr("nd", NULL), 1, to_putchar);
		else
		{
			if (cp.row < ws.ws_row)
				tputs(tgetstr("do", NULL), 1, to_putchar);
			tputs(tgetstr("cr", NULL), 1, to_putchar);
		}		
		(*curs)++;
		i++;
	}
}

void	go_left(int *curs, int n)
{
	struct winsize	ws;
	t_pos			cp;
	int				i;

	i = 0;
	ioctl(0, TIOCGWINSZ, &ws);
	cp = get_curs();
	while (i < n)
	{
		if (*curs > ws.ws_col)
			tputs(tgetstr("le", NULL), 1, to_putchar);
		else
		{
			tputs(tgetstr("up", NULL), 1, to_putchar);
			write(1, "\33[10C", 4);
		}
		(*curs)--;
		i++;
	}
}
