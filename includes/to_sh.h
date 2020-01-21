/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:16:22 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/21 20:40:39 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_SH_H
# define TO_SH_H

# include "../libft/libft.h"

# define RED_COL	"\x1b[31m"
# define GREEN_COL	"\x1B[32m"
# define RESET_COL	"\x1b[37m"

typedef struct		s_hash
{
	char			*cmd;
	char			*pth;
	struct s_hash	*nxt;
}					t_hash;

char				**my_envirenement(char **env);
char				*value_of(char **env, char *key);
int					exit_check(char *line);
void				display_prompt(int c);
void				read_line(char **line);

#endif
