/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:34:30 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/31 17:42:36 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

int		display_prompt(int c)
{
	char		*col;
	char		*path;
	static char	*tmp = NULL;

	if (c)
		col = GREEN_COL;
	else
		col = RED_COL;
	path = getcwd(NULL, 0);
	if (path)
	{
		ft_strdel(&tmp);
		tmp = ft_strrchr(path, '/');
		tmp = tmp && tmp[1] ? ft_strdup(tmp + 1) : ft_strdup(path);
		ft_strdel(&path);
	}
	ft_putstr(tmp);
	ft_putstr(col);
	ft_putstr(" $> ");
	ft_putstr(RESET_COL);
	return (ft_strlen(tmp + 4));
}
