/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:16:22 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/14 19:50:56 by awali-al         ###   ########.fr       */
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

# define UP			4283163
# define DOWN		4348699
# define LEFT		4479771
# define RIGHT		4414235
# define HOME		4741915
# define END		4610843
# define BACKSPACE	127

typedef struct		s_pos
{
	int				row;
	int				col;
}					t_pos;

typedef struct		s_line
{
	t_pos			curp;
	char			*cmd;
	char			*str;
	char			*tmp;
	int				idx;
	int				buf;
	int				col;
	int				row;
	int				prm;
	int				con;
	int				fdtty;
}					t_line;

typedef struct		s_hist
{
	struct s_hist	*prv;
	struct s_hist	*nxt;
	char			*cmd;
	int				i;
}					t_hist;

extern struct termios g_saved_attributes;

char				*char_join(char *str, int c);
int					to_putchar(int c);
void				free_2d(char ***dar);

char				**my_envirenement(char **env);
char				*value_of(char **env, char *key);
int					term_set(void);
int					display_prompt(int c);

t_hist				*open_hist(void);
void				add_to_history(t_hist **his, char *line);

char				*get_line(t_hist **his, int prm);
void				set_input_mode(void);
void				reset_input_mode(void);
void				put_in_pos(char *str);
void				add_in_pos(t_line *line);
void				del_in_pos(t_line *line);

void				prev_line(t_hist **his, t_line *line);
void				next_line(t_hist **his, t_line *line);

void				new_line(t_line *line);

void				cur_begn(t_line *line);
void				cur_rght(t_line *line);
void				cur_left(t_line *line);
void				cur_upln(t_line *line);
void				cur_down(t_line *line);

void				go_right(t_line *line);
void				go_left(t_line *line);
void				home(t_line *line);
void				end(t_line *line);

#endif
