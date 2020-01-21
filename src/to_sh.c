/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:15:48 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/21 20:45:25 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

int		main(int ac, char **av, char **ev)
{
	char	***cmd_arr;
	char	*line;
	int		i;

	(void)av;
	ac = 1;
	ev = my_envirenement(ev);
	line = ft_strdup("hi");
	while (exit_check(line))
	{
		ft_strdel(&line);
		display_prompt(ac);
		read_line(&line);
		cmd_arr = line_treatement(line);
	}
	line ? ft_strdel(&line) : 0;
	return (0);
}
