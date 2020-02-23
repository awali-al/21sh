/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:38:12 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/22 13:20:41 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static void	put_with_hgh(t_line *line)
{
	int		p;

	p = line->idx;
	tputs(tgetstr("sc", NULL), 1, to_putchar);
	home(line);
	tputs(tgetstr("cd", NULL), 1, to_putchar);
	while (line->str[line->idx])
	{
		if (line->str + line->idx == line->hgh)
			ft_putstr(WHT_BKG);
		if (line->str + line->idx == line->hgh + line->len || !line->str[line->idx + 1])
			ft_putstr(RST_BKG);
		puts_in_pos(line->str + line->idx);
		go_right(line);
	}
	tputs(tgetstr("rc", NULL), 1, to_putchar);
	line->idx = p;
}

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
	line->hgh = line->len ? line->hgh : NULL;
	put_with_hgh(line);
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
	line->hgh = line->len ? line->hgh : NULL;
	put_with_hgh(line);
	dprintf(line->fdtty, "%d  %.5s\n", line->len, line->hgh);
}

int			highlight(t_line *line)
{
	if (line->buf == ALT_LEFT && line->idx)
		lefty(line);
	else if (line->buf == ALT_RGHT && line->str[line->idx + 1])
		righty(line);
	else
		return (0);
	return (1);
}
