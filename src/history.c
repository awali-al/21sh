/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:33:04 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/06 02:17:06 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static t_hist	*new_node(char *str, int fd)
{
	t_hist	*ret;

	if (str)
	{
		ret = (t_hist*)malloc(sizeof(t_hist));
		ret->cmd = str;
		ret->fd = fd;
		ret->prv = NULL;
		ret->nxt = NULL;
		return (ret);
	}
	else
		return (NULL);
}

static char	*line_index(int i)
{
	char	*ret;
	char	*tmp;

	tmp = ft_itoa(i);
	ret = char_join(tmp, ' ');
	ft_strdel(&tmp);
	return (ret);
}

void		add_to_history(t_hist **his, char *line, int fd)
{
	t_hist	*node;
	char	*tmp;
	char	*idx;

	if (line)
	{
		idx = *his ? line_index((*his)->i + 1) : line_index(1);
		tmp = ft_strjoin(idx, line);
		ft_strdel(&idx);
		node = new_node(char_join(tmp, -1), fd);
		ft_strdel(&tmp);
		write(fd, node->cmd, ft_strlen(node->cmd));
		if (*his)
		{
			node->i = (*his)->i + 1;
			node->prv = *his;
			(*his)->nxt = node;
		}
		else
			node->i = 1;
		node->nxt = NULL;
		*his = node;
	}
}

static char	*next_cmd(int fd)
{
	char	*ret;
	char	*tmp;
	char	buf[2];

	ret = NULL;
	if (read(fd, buf, 0) == -1)
		return (NULL);
	while (read(fd, buf, 1) && buf[0] != -1)
	{
		buf[1] = '\0';
		tmp = ret;
		ret = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	return (ret);
}

t_hist		*open_hist(int *fd)
{
	t_hist	*ret;
	char	*str;

	*fd = open("~/.history", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	printf("fd = %d\n", *fd);
	str = next_cmd(*fd);
	ret = new_node(str, *fd);
	ret->i = ft_atoi(str);
	ft_strdel(&str);
	while (ret && (str = next_cmd(*fd)))
	{
		ret->prv = new_node(str, *fd);
		ret->prv->i = ft_atoi(str);
		ret->prv->nxt = ret;
		ret = ret->prv;
		ft_strdel(&str);
	}
	return (ret);
}
