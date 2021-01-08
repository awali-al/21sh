/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:53:33 by mobounya          #+#    #+#             */
/*   Updated: 2020/12/01 04:36:21 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

const	t_builtin_matcher	g_builtin_tab[7] =
{
	{"echo", &ft_echo},
	{"exit", &ft_exit},
	{"cd", &ft_changedir},
	{"setenv", &ft_setenv},
	{"unsetenv", &ft_unsetenv},
	{"env", &ft_env},
	{NULL, NULL},
};

int							ft_echo(char **command, char ***env)
{
	unsigned int index;

	env = NULL;
	index = 1;
	while (command[index])
	{
		ft_putstr(command[index]);
		if (command[index + 1])
			ft_putchar_fd(' ', 1);
		index++;
	}
	ft_putchar_fd('\n', 1);
	return (1);
}

int							ft_exit(char **command, char ***env)
{
	unsigned int	i;
	int				status;

	i = 0;
	status = 0;
	env = NULL;
	while (command[i])
		i++;
	if (i > 2)
	{
		g_exit_code = 2;
		return (g_exit_code);
	}
	else if (command[1])
		status = ft_atoi(command[1]);
	exit(status);
	return (0);
}

t_builtin_function			*is_builtin(char **cmd)
{
	uint i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strcmp(g_builtin_tab[i].name, cmd[0]))
			return (g_builtin_tab[i].function);
		i++;
	}
	return (NULL);
}

void						ft_builtin_exec(t_builtin_function *builtin,
							t_tokens *lst, char **cmd, char ***env)
{
	reset_stds(1, 0);
	g_exit_code = 0;
	ft_set_redirs(lst);
	if (g_exit_code)
		ft_errors();
	else
	{
		builtin(cmd, env);
		if (g_exit_code)
			ft_errors();
	}
	reset_stds(0, 1);
}
