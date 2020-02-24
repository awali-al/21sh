/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:38:12 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/24 23:49:13 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

/*static void	put_with_hgh(t_line *line)
{
	int		p;

	p = line->idx;
	home(line);
	while (line->str[line->idx])
	{
		if ((line->idx > (line->hgh - line->str)) &&
				line->idx > ((line->hgh + line->len) - line->str))
			ft_putstr(WHT_BKG);
		puts_in_pos(line->str + line->idx);
		go_right(line);
		if (!line->str[line->idx])
			ft_putstr(RST_BKG);
	}
}*/

static void	lefty(t_line *line)
{
	go_left(line);
	if (line->hgh)
	{
		if (line->way == -1)
		{
			line->hgh--;
			line->len++;
		}
		else
			line->len--;
	}
	else
	{
		line->hgh = line->str + line->idx;
		line->len = 1;
		line->way = -1;
	}
	if (!line->len)
		reset_highlight(line);
}

static void	righty(t_line *line)
{
	go_right(line);
	if (line->hgh)
	{
		if (line->way == 1)
			line->len++;
		else
		{
			line->hgh++;
			line->len--;
		}
	}
	else
	{
		line->hgh = line->str + line->idx - 1;
		line->len = 1;
		line->way = 1;
	}
	if (!line->len)
		reset_highlight(line);
}

int			highlight(t_line *line)
{
	if (line->buf == ALT_LEFT && line->idx)
		lefty(line);
	else if (line->buf == ALT_RGHT && line->str[line->idx])
		righty(line);
	else
		return (0);
	dprintf(line->fdtty, "%d  %.*s\n", line->len, line->len, line->hgh);
	return (1);
}
