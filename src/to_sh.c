/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:15:48 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/28 14:38:06 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

int		main(int ac, char **av, char **ev)
{
	char	***cmd_arr;
	char	*line;
	t_pos	pos;

	(void)av;
	ac = 1;
	ev = my_envirenement(ev);
	line = ft_strdup("hi");
	ft_putstr(CLR_SCRN);
	while (exit_check(line))
	{
		ft_strdel(&line);
		pos.col = display_prompt(ac);
		line = get_line(pos);
		ft_putstr(line);
	}
	line ? ft_strdel(&line) : 0;
	return (0);
}
