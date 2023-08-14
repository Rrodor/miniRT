/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:00:43 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/14 15:03:13 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	a_free(t_a *a)
{
	free(a->id);
	free(a);
}

void	c_free(t_c *c)
{
	free(c->id);
	free(c);
}

void	l_free(t_l *l)
{
	free(l->id);
	free(l);
}

void	freelst(void *content)
{
	t_a	*a;

	a = (t_a *)content;
	if (ft_strncmp(a->id, "A", 1) == 0)
		a_free(((t_a *)content));
	else if (ft_strncmp(a->id, "C", 1) == 0)
		c_free(((t_c *)content));
	else if (ft_strncmp(a->id, "L", 1) == 0)
		l_free(((t_l *)content));
	else if (ft_strncmp(a->id, "sp", 2) == 0)
		sp_free(((t_sp *)content));
	else if (ft_strncmp(a->id, "pl", 2) == 0)
		pl_free(((t_pl *)content));
	else if (ft_strncmp(a->id, "cy", 2) == 0)
		cy_free(((t_cy *)content));
}

void	freetab(void *content)
{
	int	i;

	i = 0;
	while (((char **)content)[i])
	{
		free(((char **)content)[i]);
		i++;
	}
	free(content);
}
