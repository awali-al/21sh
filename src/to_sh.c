/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:15:48 by awali-al          #+#    #+#             */
/*   Updated: 2020/11/12 16:37:10 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh_rl.h"

int		main(int ac, char **av, char **ev)
{
	t_hist	*his;
	char	*line;

	(void)av;
	tcgetattr(0, &g_saved_attributes);
	ac = 1;
	his = open_hist();
	ev = my_envirenement(ev);
	line = ft_strdup("hi");
	if (!term_set() && line && ft_strcmp(line, "exit"))
	{
		ft_strdel(&line);
		line = get_line(&his, NULL, ac);
		write(1, "\n", 1);
		printf("%s\n", line);
		add_to_history(&his, line);
	}
	ev ? free_2d(&ev) : 0;
	return (0);
}
