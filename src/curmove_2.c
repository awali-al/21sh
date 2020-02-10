/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curmove_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:34:44 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/09 20:36:03 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void	cur_down(t_line *line)
{
	tputs(tgetstr("do", NULL), 1, to_putchar);
	line->cupo.row++;
}

void	cur_upln(t_line *line)
{
	tputs(tgetstr("up", NULL), 1, to_putchar);
	line->cupo.row--;
}
