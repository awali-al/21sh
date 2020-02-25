/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:09:19 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/25 22:39:16 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh_rl.h"

void	putc_in_pos(char c)
{
	tputs(tgetstr("sc", NULL), 1, to_putchar);
	tputs(tgetstr("cd", NULL), 1, to_putchar);
	ft_putchar(c);
	tputs(tgetstr("rc", NULL), 1, to_putchar);
}

void	put_in_pos(char *str)
{
	tputs(tgetstr("sc", NULL), 1, to_putchar);
	tputs(tgetstr("cd", NULL), 1, to_putchar);
	ft_putstr(str);
	tputs(tgetstr("rc", NULL), 1, to_putchar);
}

int		prv_end(t_line *line)
{
	int		n;
	int		i;

	i = line->idx - 1;
	while (i >= 0 && line->str[i] != '\n')
		i--;
	n = line->idx - i;
	if (i < 0)
		n += line->prm;
	return (n % line->col);
}

int		nxt_end(t_line *line)
{
	char	*pn;
	int		l;
	int		e;

	e = (line->row - line->curp.row + 1) * line->col - line->curp.col;
	if ((pn = ft_strchr(line->str + line->idx, '\n')) &&
			pn + line->curp.col = line->col)
		return (1);
	else
	{
		l = ft_strlen
	}
}

/*int		nxt_end(t_line *line)
{
	char	*n;

	n = ft_strchr(line->str + line->idx, '\n');
	if (n)
		return (n - (line->str + line->idx));
	else
		return (ft_strlen(line->str + line->idx));
}*/
