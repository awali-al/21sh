/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:33:04 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/05 22:00:28 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static char	*char_join(char *str, int c)
{
	char	*ret;
	int		i;

	ret = ft_strnew(ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = c;
	return (ret);
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
	t_hist	*new_node;
	char	*tmp;
	char	*idx;

	idx = line_index((*his)->i + 1);
	tmp = ft_strjoin(idx, line);
	new_node = (t_hist*)malloc(sizeof(t_hist));
	new_node->cmd = char_join(line, -1);
	write(fd, new_node->cmd, ft_strlen(new_node->cmd));
	new_node->fd = (*his)->fd;
	new_node->i = (*his)->i + 1;
	new_node->nxt = NULL;
	new_node->prv = (*his);
	(*his)->nxt = new_node;
	(*his) = new_node;
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
	t_hist	*tmp;
	char	*str;

	ret = NULL;
	*fd = open("~/.history", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	if ((str = next_cmd(*fd)))
	{
		tmp->cmd = ft_strchr(str, ' ') + 1;
	}
}
