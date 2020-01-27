/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:16:22 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/27 21:19:23 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_SH_H
# define TO_SH_H

# include <stdio.h>
# include <termios.h>

# include "../libft/libft.h"

# define RED_COL	"\x1b[31m"
# define GREEN_COL	"\x1B[32m"
# define RESET_COL	"\x1b[37m"
# define CLR_SCRN	"\033[2J"

typedef struct		s_hash
{
	char			*cmd;
	char			*pth;
	struct s_hash	*nxt;
}					t_hash;

typedef struct		s_pos
{
	int				col;
	int				row;
}					t_pos;

extern struct termios g_saved_attributes;

char				**my_envirenement(char **env);
char				*value_of(char **env, char *key);
int					exit_check(char *line);
int					display_prompt(int c);

void				set_input_mode(void);
void				reset_input_mode(void);
char				*get_line(int op);
void				put_in_pos(char b, int pos);

#endif
