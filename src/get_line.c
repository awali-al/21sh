/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:46:50 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/01 00:20:18 by awali-al         ###   ########.fr       */
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

static void	store_print(char **ret, int b, int *curs, int pos)
{
	if (ft_isprint(b))
		add_in_pos(ret, b, curs);
	else if (b == RIGHT && *curs < ft_strlen(*ret))
		go_right(curs, 1);
	else if (b == END)
		go_right(curs, ft_strlen(*ret + *curs));
	else if (b == HOME)
		go_left(curs, *curs);
	else if (b == LEFT && *curs)
		go_left(curs, 1);
	else if (b == BACKSPACE && *curs)
		del_in_pos(ret, curs);
}

char		*get_line(int pos)
{
	char	*ret;
	int		b;
	int		c;
	int		curs;

	set_input_mode();
	c = 0;
	curs = 0;
	ret = ft_strdup("");
	while (1)
	{
		b = 0;
		read(0, &b, 4);
		if (condition(b, c))
			break ;
		else
		{
			c = qdq_con(b, c);
			store_print(&ret, b, &curs, pos);
		}
	}
	reset_input_mode();
	return (ret);
}
