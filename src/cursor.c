/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:41:17 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/13 18:15:18 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static int	nxt_end(t_line *line)
{
	char	*n;

	n = ft_strchr(line->str + line->idx, '\n');
	if (n)
		return (n - (line->str + line->idx));
	else
		return (ft_strlen(line->str + line->idx));
}

void		go_right(t_line *line)
{
	int		l;

	line->idx++;
	if (line->str[line->idx] == '\n' || line->col == line->curp.col)
	{
		cur_down(line);
		cur_begn(line);
	}
	else if (line->row != line->curp.row)
		cur_rght(line);
	else
	{
		cur_rght(line);
		if ((l = nxt_end(line)) && (line->curp.col + l) == line->col + 2)
		{
			tputs(tgetstr("sc", NULL), 1, to_putchar);
			tputs(tgetstr("do", NULL), 1, to_putchar);
			tputs(tgetstr("rc", NULL), 1, to_putchar);
		}
	}
}

static int	prv_end(t_line *line)
{
	int		n;

	n = 0;
	n = line->idx - 2;
	while (n >= 0 && line->str[n] != '\n')
		n--;
	if (n < 0)
		n = line->prm;
	else if (!n)
		n += line->prm;
	return (n % line->col + 1);
	return (0);
}

void		go_left(t_line *line)
{
	if (line->curp.col > 1)
		cur_left(line);
	else
	{
		cur_upln(line);
		if (line->str[line->idx - 1] == '\n')
			line->curp.col = prv_end(line);
		else
			line->curp.col = line->col - 1;
		tputs(tgoto(tgetstr("ch", NULL), 0, line->curp.col), 1, to_putchar);
	}
	line->idx--;
}
