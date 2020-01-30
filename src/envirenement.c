/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirenement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:06:42 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/30 14:53:49 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

char		*value_of(char **env, char *key)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	ret = NULL;
	tmp = ft_strjoin(key, "=");
	while (env[i] && ft_strstr(env[i], tmp) != env[i])
		i++;
	ft_strdel(&tmp);
	if (env[i])
		ret = ft_strchr(env[i], '=') + 1;
	return (ret);
}

void		free_2d(char ***dar)
{
	int		i;

	i = 0;
	if (dar)
		while ((*dar)[i])
		{
			ft_strdel(&(*dar)[i]);
			i++;
		}
	free(*dar);
	*dar = NULL;
}

char		**my_envirenement(char **env)
{
	char	**ret;
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (env[n])
		n++;
	ret = (char**)malloc((n + 1) * sizeof(char*));
	while (i < n)
	{
		ret[i] = ft_strdup(env[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
