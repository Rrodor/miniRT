/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:37:28 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/09 18:15:51 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	sp_cmp(t_sp *sp1, t_sp *sp2)
{
	if (sp1->radius != sp2->radius)
		return (1);
	else if (sp1->pos->x != sp2->pos->x || sp1->pos->y != sp2->pos->y ||
			sp1->pos->z != sp2->pos->z)
		return (1);
	else if (sp1->color->r != sp2->color->r || sp1->color->g != sp2->color->g ||
			sp1->color->b != sp2->color->b)
		return (1);
	return (0);
}

int	pl_cmp(t_pl *pl1, t_pl *pl2)
{
	if (pl1->pos->x != pl2->pos->x || pl1->pos->y != pl2->pos->y ||
			pl1->pos->z != pl2->pos->z)
		return (1);
	else if (pl1->dir->x != pl2->dir->x || pl1->dir->y != pl2->dir->y ||
			pl1->dir->z != pl2->dir->z)
		return (1);
	else if (pl1->color->r != pl2->color->r || pl1->color->g != pl2->color->g ||
			pl1->color->b != pl2->color->b)
		return (1);
	return (0);
}

int	cy_cmp(t_cy *cy1, t_cy *cy2)
{
	if (cy1->pos->x != cy2->pos->x || cy1->pos->y != cy2->pos->y ||
			cy1->pos->z != cy2->pos->z)
		return (1);
	else if (cy1->dir->x != cy2->dir->x || cy1->dir->y != cy2->dir->y ||
			cy1->dir->z != cy2->dir->z)
		return (1);
	else if (cy1->radius != cy2->radius)
		return (1);
	else if (cy1->height != cy2->height)
		return (1);
	else if (cy1->color->r != cy2->color->r || cy1->color->g != cy2->color->g ||
			cy1->color->b != cy2->color->b)
		return (1);
	return (0);
}

int	obj_cmp(void *obj1, void *obj2)
{
	t_a *a1;
	t_a *a2;

	a1 = (t_a *)obj1;
	a2 = (t_a *)obj2;
	if (!a1 || !a2)
		return (1);
	else if (ft_strncmp(a1->id, "A", 1) == 0 || ft_strncmp(a2->id, "A", 1) == 0)
		return (0);
	else if (ft_strncmp(a1->id, "C", 1) == 0 || ft_strncmp(a2->id, "C", 1) == 0)
		return (0);
	else if (ft_strncmp(a1->id, "L", 1) == 0 || ft_strncmp(a2->id, "L", 1) == 0)
		return (0);
	if (ft_strncmp(a1->id, a2->id, 2) != 0)
		return (1);
	else if (ft_strncmp(a1->id, "sp", 2) == 0)
		return (sp_cmp(obj1, obj2));
	else if (ft_strncmp(a1->id, "pl", 2) == 0)
		return (pl_cmp(obj1, obj2));
	else if (ft_strncmp(a1->id, "cy", 2) == 0)
		return (cy_cmp(obj1, obj2));
	return (0);
}
