/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:36:49 by awali-al          #+#    #+#             */
/*   Updated: 2020/11/20 10:49:39 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void		home(t_line *line)
{
	while (line->idx)
		go_left(line);
}

void		end(t_line *line)
{
	while (line->str[line->idx])
		go_right(line);
}

static void	prv_word(t_line *line)
{
	while (line->idx && !ft_isalnum(line->str[line->idx - 1]))
		go_left(line);
	while (line->idx && ft_isalnum(line->str[line->idx - 1]))
		go_left(line);
}

static void	nxt_word(t_line *line)
{
	while (line->str[line->idx] && ft_isalnum(line->str[line->idx]))
		go_right(line);
	while (line->str[line->idx] && !ft_isalnum(line->str[line->idx]))
		go_right(line);
}

int			navigation(t_line *line)
{
	if (line->buf == HOME)
		home(line);
	else if (line->buf == END)
		end(line);
	else if (line->buf == PRV_WRD)
		prv_word(line);
	else if (line->buf == NXT_WRD)
		nxt_word(line);
	else
		return (0);
	return (1);
}
