/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:15:48 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/01 21:25:15 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

int		main(int ac, char **av, char **ev)
{
	t_line	*bot;
	char	*line;
	int		prm;

	(void)av;
	ac = 1;
	bot = NULL;
	ev = my_envirenement(ev);
	line = ft_strdup("hi");
	if (!term_set())
		while (exit_check(line))
		{
			ft_strdel(&line);
			prm = display_prompt(ac);
			line = get_line(&bot, prm);
		}
	ev ? free_2d(&ev) : 0;
	line ? ft_strdel(&line) : 0;
	return (0);
}
