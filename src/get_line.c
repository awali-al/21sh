/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:46:50 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/27 21:50:18 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static int	condition(int b, int c)
{
	if (b == '\004' || (!c && b == '\n'))
		return (1);
	else
		return (0);
}

static int	qdq_con(int b, int c)
{
	if (c && b != c)
		return (c);
	else if (!c && (b == '\'' || b == '\"'))
		return (b);
	else
		return (0);
}

static void	add_in_pos(char **str, char b, int pos)
{
	char	*tmp;
	int		n;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = *str;
	n = ft_strlen(tmp);
	*str = ft_strnew(n + 1);
	while (tmp[i])
	{
		if (i != pos)
		{
			(*str)[j] = tmp[i];
			i++;
		}
		else
			(*str)[j] = b;
		j++;
	}
	ft_strdel(&tmp);
}

static void	store_print(char **ret, char b, t_pos *i, int op)
{
	if (ft_isprint(b))
	{
		add_in_pos(ret, b, op + i->col);
		put_in_pos(i, b, op);
		i++;
	}
	else
		special_char(b, i, op);
}

char		*get_line(int op)
{
	t_pos	i;
	char	*ret;
	int		b;
	int		c;

	set_input_mode();
	c = 0;
	b = 0;
	i = ini_pos();
	ret = ft_strnew(1);
	while (1)
	{
		read(STDIN_FILENO, &b, 4);
		if (condition(b, c))
			break ;
		else
		{
			c = qdq_con(b, c);
			store_print(&ret, b, &i, op);
		}
	}
	reset_input_mode();
	return (ret);
}
