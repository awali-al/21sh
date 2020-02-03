/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:54:13 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/02 11:24:13 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

// static t_line	*dup_node(t_line *bot)
// {
// 	t_line	*ret;

// 	ret = (t_line*)malloc(sizeof(t_line));
// 	ret->str = ft_strdup(bot->str);
// 	ret->prv = NULL;
// 	ret->nxt = NULL;
// 	ret->curs = bot->curs;
// 	ret->buf = 0;
// 	ret->col = bot->col;
// 	ret->row = bot->row;
// 	ret->prm = bot->prm;
// 	ret->con = bot->con;
// 	return (ret);
// }

// t_line	*duplic_history(t_line *bot)
// {
// 	t_line	*ret;
// 	t_line	*tmp;

// 	ret = NULL;
// 	if (bot)
// 		ret = dup_node(bot);
// 	tmp = ret;
// 	while (bot && bot->prv)
// 	{
// 		tmp->prv = dup_node(bot->prv);
// 		tmp->prv->nxt = tmp;
// 		tmp = tmp->prv;
// 		bot = bot->prv;
// 	}
// 	return (ret);
// }

static void	clear_node(t_line **node)
{
	ft_strdel(&((*node)->str));
	(*node)->prv = NULL;
	(*node)->nxt = NULL;
	free(*node);
	*node = NULL;
}

void	add_to_history(t_line **bot, t_line *line)
{
	t_line	*tmp;

	if (*bot)
	{
		if (!line->nxt && !line->prv)
		{
			(*bot)->nxt = line;
			line->prv = *bot;
		}
		else
		{
			tmp = *bot;
			if ((*bot)->prv)
			{
				(*bot)->prv->nxt = line;
				line->prv = (*bot)->prv;
			}
			clear_node(&tmp);
		}
	}
	*bot = line;
}

void	clear_history(t_line **bot)
{
	if (*bot)
	{
		if ((*bot)->prv)
			clear_history(&(*bot)->prv);
		clear_node(bot);
	}
}

t_line	*prv_line(t_line *line)
{
	int		i;

	printf("[%s]\n", line->str);
	if (line->prv)
	{
		i = line->curs;
		line = line->prv;
		line->col = line->nxt->col;
		line->row = line->nxt->row;
		// printf("[%s]\n", line->str);
		while(i-- > 0)
			go_left(&line);
		put_in_pos(line->str);
		i = ft_strlen(line->str);
		while (i-- > 0)
			go_right(&line);
	}
	return (line);
}

t_line	*nxt_line(t_line *line)
{
	if (line->nxt)
	{
		line = line->nxt;
		line->col = line->prv->col;
		line->row = line->prv->row;
		home(line);
		put_in_pos(line->str);
	}
	return (line);
}
