/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:34:36 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/27 20:45:48 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

void	put_in_pos(char b, int pos)
{
	struct winsize	ws;
	int				col;
	int				row;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	row = get_row();
	if (pos > ws.ws_col)
	{
		row++;
		pos -= ws.ws_col;
	}
	
}
