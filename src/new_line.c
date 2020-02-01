/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:52:14 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/01 19:38:36 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static int	pri_pro(t_line *line)
{
	if (line->con = '|')
	{
		ft_putstr("pipe> ");
		return (6);
	}
	else if (line->con == '\'')
	{
		ft_putstr("quote> ");
		return (7);
	}
	else if (line->con = '\"')
	{
		ft_putstr("dquote> ");
		return (8);
	}
}

void		new_line(t_line *line)
{
	char	*tmp;

	add_in_pos(line);
	tmp = line->cmd;
	line->cmd = ft_strjoin(tmp, line->str);
	ft_strdel(&tmp);
	ft_strdel(&line->str);
	line->prm = pri_pro(line);
}
