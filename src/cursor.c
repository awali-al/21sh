/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:41:17 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/10 01:30:18 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static int	nxt_end(char *str)
{
	char	*l;

	if ((l = ft_strchr(str, '\n')))
		return (l - str);
	else
		return (ft_strlen(str));
}

static int	prv_end(t_line *line)
{
	int		c;
	int		i;

	c = 0;
	i = line->idx - 1;
	i--;
	while (i >= 0 && line->str[i] != '\n')
	{
		i--;
		c++;
	}
	if (i)
		return (c % line->col);
	else
		return ((c + line->prm));
}

void		go_right(t_line *line)
{
	int		l;

	line->idx++;
	l = nxt_end(line->str + line->idx);
	if (line->row == line->cupo.row)
	{
		if (line->cupo.col == line->col || line->str[line->idx] == '\n')
			cur_begl(line);
		else if (l)
		{
			cur_rght(line);
			if ((l + line->cupo.col) == line->col)
				cur_upln(line);
		}
	}
	else
	{
		if (line->cupo.col == line->col || line->str[line->idx] == '\n')
		{
			cur_begl(line);
			cur_down(line);
		}
		else
			cur_rght(line);
	}
}

void		go_left(t_line *line)
{
	if (line->cupo.col % line->col == 0)
	{
		cur_upln(line);
		cur_endl(line);
	}
	else if ((line->idx > 0 && line->str[line->idx] == '\n'))
	{
		cur_upln(line);
		line->cupo.col = prv_end(line);
		tputs(tgoto(tgetstr("ch", NULL), 0, line->cupo.col), 1, to_putchar);
	}
	else
		cur_left(line);
	line->idx--;
}
