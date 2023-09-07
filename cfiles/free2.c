/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:58:57 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/07 15:50:10 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	sp_free(t_sp *sp)
{
	free(sp->id);
	free(sp->pos);
	free(sp->color);
	free(sp);
}

void	pl_free(t_pl *pl)
{
	free(pl->id);
	free(pl->pos);
	free(pl->dir);
	free(pl->color);
	free(pl);
}

void	cy_free(t_cy *cy)
{
	free(cy->id);
	free(cy->pos);
	free(cy->dir);
	free(cy->color);
	free(cy);
}

void	ray_free(t_ray *ray)
{
	if (!ray)
		return ;
	free(ray->ori);
	free(ray->dir);
	free(ray);
}

void	viewport_free(t_viewport *viewport)
{
	free(viewport->u);
	free(viewport->v);
	free(viewport->d_u);
	free(viewport->d_v);
	free(viewport->upper_left_corner);
	free(viewport->p_pixel_00);
	free(viewport);
}
