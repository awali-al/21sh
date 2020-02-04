/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:33:04 by awali-al          #+#    #+#             */
/*   Updated: 2020/02/04 20:30:13 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/to_sh.h"

t_hist	*open_hist(int *fd)
{
	t_hist	*ret;

	ret = NULL;
	open("~/.history", O_CREAT);
	*fd = open("~/.history", O_RDWR);
	
}
