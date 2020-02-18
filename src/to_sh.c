/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:15:48 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/18 19:00:21 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

int		main(int ac, char **av, char **ev)
{
	t_hist	*his;
	char	*line;
	int		prm;

	(void)av;
	tcgetattr(0, &g_saved_attributes);
	ac = 1;
	his = open_hist();
	ev = my_envirenement(ev);
	line = ft_strdup("hi");
	if (!term_set())
		while (ft_strcmp(line, "exit"))
		{
			ft_strdel(&line);
			prm = display_prompt(ac);
			line = get_line(&his, prm);
			write(1, "\n", 1);
		}
	ev ? free_2d(&ev) : 0;
	return (0);
}
