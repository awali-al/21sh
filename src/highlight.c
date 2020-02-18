/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:38:12 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/18 19:41:23 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

static void	lefty(t_line *line)
{
	if (line->hgh && line->hgh == )
	{
	}
}

int			highlight(t_line *line)
{
	if (line->buf == ALT_LEFT)
		lefty(line);
	else if (line->buf == ALT_RGHT)
		righty(line);
	else
		return (0);
	return (1);
}
