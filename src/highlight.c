/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:38:12 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/20 15:42:22 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static void	put_with_hgh(t_line *line)
{
	int		i;
	
	tputs(tgetstr("sc", NULL), 1, to_putchar);
	while (line->str + line->idx > line->hgh)
		go_right(line);
	tputs(tgetstr("cd", NULL), 1, to_putchar);
	i = 0;
	while (line->hgh[i])
	{
		if (i < line->len)
		{
			ft_putstr(WHT_BKG);
			ft_putstr(BLK_COL);
			ft_putchar(line->hgh[i]);
			ft_putstr(RST_COL);
			ft_putstr(RST_BKG);
		}
		else
			ft_putchar(line->hgh[i]);
		i++;
	}
	tputs(tgetstr("rc", NULL), 1, to_putchar);
}

static void	lefty(t_line *line)
{
	go_left(line);
	if (line->hgh)
	{
		if (line->hgh == line->str + line->idx + 1)
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
		line->len++;
	}
	put_with_hgh(line);
}

static void	righty(t_line *line)
{
	go_right(line);
	if (line->hgh)
	{
		if (line->hgh == line->str + line->idx - 1)
		{
			line->hgh++;
			line->len--;
		}
		else
			line->len++;
	}
	else
	{
		line->hgh = line->str + line->idx - 1;
		line->len++;
	}
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
