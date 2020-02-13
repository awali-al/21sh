/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:52:14 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/13 18:16:46 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static void	nxt_line_curs(t_line *line)
{
	cur_down(line);
	cur_begn(line);
}

void		new_line(t_line *line)
{
	char	*tmp;
	int		i;

	tmp = line->cmd;
	line->cmd = ft_strjoin(tmp, line->str);
	line->cmd = char_join(line->cmd, '\n');
	ft_strdel(&tmp);
	ft_strdel(&line->str);
	line->str = ft_strnew(1);
	nxt_line_curs(line);
	if (line->con == '\'')
	{
		put_in_pos("quote> ");
		line->prm = 7;
	}
	else
	{
		put_in_pos("dquote> ");
		line->prm = 8;
	}
	i = 0;
	while (i++ < line->prm)
		go_right(line);
	line->idx = 0;
}
