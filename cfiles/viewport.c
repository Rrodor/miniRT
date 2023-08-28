/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:19:22 by aramon            #+#    #+#             */
/*   Updated: 2023/08/28 14:44:44 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "miniRT.h"
#include "viewport.h"

t_viewport	*init_viewport()
{
	t_viewport	*viewport;

	viewport = (t_viewport *)malloc(sizeof(t_viewport));
	if (!viewport)
		return (NULL);
	viewport->height = 2.0;
	viewport->width = viewport->height * ((double)WINX / (double)WINY);
	viewport->focal_length = 1.0;
	viewport->u = vec_new(viewport->width, 0, 0);
	viewport->v = vec_new(0, -viewport->height, 0);
	viewport->d_u = vec_new(viewport->u->x / WINX, 
		viewport->u->y / WINX, viewport->u->z / WINX);
	viewport->d_v = vec_new(viewport->v->x / WINY,
		viewport->v->y / WINY, viewport->v->z / WINY);
	viewport->upper_left_corner = vec_sub(vec_sub(vec_sub(vec_new(0, 0, 0),
		vec_new(0, 0, viewport->focal_length)), vec_div_num(viewport->u, 2.0)),
		vec_div_num(viewport->v, 2.0));
	viewport->p_pixel_00 = vec_add(viewport->upper_left_corner,
		vec_add(vec_mult_num(viewport->d_u, 0.5),
		vec_mult_num(viewport->d_v, 0.5)));
	return (viewport);
}

// Must be added somewhere
void	free_viewport(t_viewport *viewport)
{
	if (!viewport)
		return ;
	vec_free(viewport->u);
	vec_free(viewport->v);
	vec_free(viewport->d_u);
	vec_free(viewport->d_v);
	vec_free(viewport->upper_left_corner);
	vec_free(viewport->p_pixel_00);
	free(viewport);
}

t_vec	*get_pixel_center(t_viewport *v, int x, int y)
{
	t_vec	*pixel_center;

	pixel_center = vec_add(v->p_pixel_00,
		vec_add(vec_mult_num(v->d_u, x), vec_mult_num(v->d_v, y)));
	//printf("pixel_center: %f %f %f\n", pixel_center->x, pixel_center->y, pixel_center->z);
	return (pixel_center);
}