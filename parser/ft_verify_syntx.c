/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_syntx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:52:45 by mobounya          #+#    #+#             */
/*   Updated: 2020/11/20 10:50:16 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

/*
** First check of syntax
*/

int		ft_verify_syntax(t_tokens *lst)
{
	int		alternatives[ARRAY_SIZE];

	ft_get_alernative_ids(-1, alternatives, ARRAY_SIZE);
	while (lst)
	{
		if ((ft_compare_token(lst->token_id, alternatives)) == 0)
			return (0);
		if (lst->token_id != SEMI && (lst->token_id >= 2 \
			&& lst->token_id <= 11))
		{
			if (lst->next == NULL)
				return (0);
		}
		ft_get_alernative_ids(lst->token_id, alternatives, ARRAY_SIZE);
		lst = lst->next;
	}
	return (1);
}

int		ft_traverse_verify(t_ast *root)
{
	if (root == NULL)
		return (1);
	if (ft_traverse_verify(root->left) == 0)
		return (0);
	if (root->token->token_id == SIMPLE_COMMAND && \
		ft_verify_syntax(root->token->command_tokens) == 0)
	{
		return (0);
	}
	if (ft_traverse_verify(root->right) == 0)
		return (0);
	return (1);
}
