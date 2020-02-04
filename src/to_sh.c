/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:15:48 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/04 19:35:27 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

int		main(int ac, char **av, char **ev)
{
	t_hist	*his;
	char	*line;
	int		prm;
	int		fd;

	(void)av;
	tcgetattr(0, &g_saved_attributes);
	ac = 1;
	ev = my_envirenement(ev);
	line = ft_strdup("hi");
	his = open_hist(&fd);
	if (!term_set())
		while (ft_strcmp(line, "exit"))
		{
			ft_strdel(&line);
			prm = display_prompt(ac);
			line = get_line(his, prm);
			write(1, "\n", 1);
		}
	close(fd);
	ev ? free_2d(&ev) : 0;
	return (0);
}
