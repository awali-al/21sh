/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:16:22 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/01 11:30:19 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_SH_H
# define TO_SH_H

# include <stdio.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>

# include "../libft/libft.h"

# define RED_COL	"\x1b[31m"
# define GREEN_COL	"\x1B[32m"
# define RESET_COL	"\x1b[37m"
# define CLR_SCRN	"\033[2J"

# define UP			4283163
# define DOWN		4348699
# define LEFT		4479771
# define RIGHT		4414235
# define HOME		4741915
# define END		4610843
# define BACKSPACE	127

typedef struct		s_line
{
	char			*str;
	int				curs;
	int				b;
}					t_line;

typedef struct		s_pos
{
	int				col;
	int				row;
}					t_pos;

extern struct termios g_saved_attributes;

int					to_putchar(int c);
void				go_right(int *curs, int n);
void				go_left(int *curs, int n);

char				**my_envirenement(char **env);
char				*value_of(char **env, char *key);
void				free_2d(char ***dar);
int					term_set(void);
int					display_prompt(int c);

void				set_input_mode(void);
void				reset_input_mode(void);
char				*get_line(int pos);
void				put_in_pos(char *str);
void				add_in_pos(t_line *line);
void				del_in_pos(t_line *line);

#endif
