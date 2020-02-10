/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:08:52 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/09 21:25:31 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void	cur_left(t_line *line)
{
	tputs(tgetstr("le", NULL), 1, to_putchar);
	line->cupo.col--;
}

void	cur_rght(t_line *line)
{
	tputs(tgetstr("nd", NULL), 1, to_putchar);
	line->cupo.col++;
}

void	cur_endl(t_line *line)
{
	tputs(tgoto(tgetstr("ch", NULL), 0, line->col - 1), 1, to_putchar);
	line->cupo.col = line->col - 1;
}

void	cur_begl(t_line *line)
{
	tputs(tgetstr("cr", NULL), 1, to_putchar);
	line->cupo.col = 0;
}
