/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:19:22 by aramon            #+#    #+#             */
/*   Updated: 2023/09/07 16:00:04 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "miniRT.h"
#include "viewport.h"

t_viewport	*init_viewport(t_cam *cam)
{
	t_viewport	*viewport;
	t_vec		*tmp;
	t_vec		*tmp2;
	t_vec		*tmp3;

	viewport = (t_viewport *)malloc(sizeof(t_viewport));
	if (!viewport)
		return (NULL);
	viewport->height = 2.0;
	viewport->width = viewport->height * ((double)WINX / (double)WINY);
	viewport->focal_length = 2.0 * atan(100 / (cam->fov * 2.0));
	viewport->u = vec_new(viewport->width, 0, 0);
	viewport->v = vec_new(0, -viewport->height, 0);
	viewport->d_u = vec_new(viewport->u->x / WINX,
		viewport->u->y / WINX, viewport->u->z / WINX);
	viewport->d_v = vec_new(viewport->v->x / WINY,
		viewport->v->y / WINY, viewport->v->z / WINY);
	tmp = vec_new(0, 0, viewport->focal_length);
	tmp2 = vec_sub(cam->pos, tmp);
	free(tmp);
	tmp = vec_div_num(viewport->u, 2.0);
	tmp3 = vec_sub(tmp2, tmp);
	free(tmp);
	free(tmp2);
	tmp = vec_div_num(viewport->v, 2.0);
	viewport->upper_left_corner = vec_sub(tmp3, tmp);
	free(tmp);
	free(tmp3);
	tmp = vec_mult_num(viewport->d_u, 0.5);
	tmp2 = vec_mult_num(viewport->d_v, 0.5);
	tmp3 = vec_add(tmp, tmp2);
	viewport->p_pixel_00 = vec_add(viewport->upper_left_corner, tmp3);
	free(tmp);
	free(tmp2);
	free(tmp3);
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
	t_vec	*tmp1;
	t_vec	*tmp2;
	t_vec	*tmp3;

	tmp1 = vec_mult_num(v->d_u, x);
	tmp2 = vec_mult_num(v->d_v, y);
	tmp3 = vec_add(tmp1, tmp2);
	pixel_center = vec_add(v->p_pixel_00,tmp3);
	free(tmp1);
	free(tmp2);
	free(tmp3);
	return (pixel_center);
}
