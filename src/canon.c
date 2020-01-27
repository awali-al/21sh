/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:58:28 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/26 18:00:48 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

struct termios g_saved_attributes;

void	reset_input_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &g_saved_attributes);
}

void	set_input_mode(void)
{
	struct termios	tattr;
	char			*name;

	if (!isatty(STDIN_FILENO))
	{
		dprintf(2, "Not a terminal.\n");
		exit(EXIT_FAILURE);
	}
	tcgetattr(STDIN_FILENO, &g_saved_attributes);
	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ICANON | ECHO);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}
