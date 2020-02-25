/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:04:16 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/25 14:39:49 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh_rl.h"

int		conditions(t_line *line)
{
	char	*str;
	char	*tmp;
	int		i;

	if (line->buf != '\n' && line->buf != '\004')
		return (1);
	str = ft_strjoin(line->cmd, line->str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (!(tmp = ft_strchr(str + i + 1, str[i])))
			{
				line->con = str[i];
				ft_strdel(&str);
				return (1);
			}
			else
				i = tmp - str;
		}
		i++;
	}
	ft_strdel(&str);
	return (0);
}
