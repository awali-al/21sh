/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:16:22 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/04 19:34:52 by awali-al         ###   ########.fr       */
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
	char			*tmp;
	int				curs;
	int				buf;
	int				col;
	int				row;
	int				prm;
	int				con;
}					t_line;

typedef struct		s_hist
{
	char			*cmd;
	int				i;
	struct s_hist	*prv;
	struct s_hist	*nxt;
}					t_hist;

extern struct termios g_saved_attributes;

char				**my_envirenement(char **env);
char				*value_of(char **env, char *key);
void				free_2d(char ***dar);
int					term_set(void);
int					display_prompt(int c);

char				*get_line(t_hist *his, int prm);
void				set_input_mode(void);
void				reset_input_mode(void);
void				put_in_pos(char *str);
void				add_in_pos(t_line *line);
void				del_in_pos(t_line *line);

int					to_putchar(int c);
void				go_right(t_line *line);
void				go_left(t_line *line);
void				home(t_line *line);
void				end(t_line *line);

#endif
