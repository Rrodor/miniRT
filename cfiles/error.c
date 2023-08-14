/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:49:26 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/13 17:12:35 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	error(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strcmp(((char **)tmp->content)[0], "A") == 0)
			if (error_a(tmp->next) == -1)
				return (-1);
		if (ft_strcmp(((char **)tmp->content)[0], "C") == 0)
			if (error_c(tmp->next) == -1)
				return (-1);
		if (ft_strcmp(((char **)tmp->content)[0], "L") == 0)
			if (error_l(tmp->next) == -1)
				return (-1);
		else
			if (errorform(((char **)tmp->content)[0]) == -1)
				return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	error_a(char **tab)
{
	if (ft_tablen(tab) != 3)
		return (-1);
	return (0);
}
