/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:34:36 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/30 21:09:29 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static t_pos	get_cursor(void)
{
	t_pos			ret;
	char			**coor;
	char			buf[5];

	write(1, "\033[6n", 4);
	read(0, buf, 4);
	buf[4] = '\0';
	coor = ft_strsplit(buf, ';');
	ret.col = ft_atoi(coor[0]);
	ret.row = ft_atoi(coor[1]);
	free_2d(&coor);
	return (ret);
}

void			put_in_pos(char *str, int i, int pos)
{
	struct winsize	ws;
	t_pos			cp;
	int				n;

	ioctl(TIOCGWINSZ, &ws);
	cp = get_cursor();
	n = ft_strlen(str);
	if ((i + pos) <= ws.ws_col)
	{
		tputs(tgetstr("cd", NULL), 1, to_puthar);
		ft_putstr(str);
		
	}
}
