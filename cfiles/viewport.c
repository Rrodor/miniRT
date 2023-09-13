/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:19:22 by aramon            #+#    #+#             */
/*   Updated: 2023/09/13 20:11:22 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "miniRT.h"
#include "viewport.h"

t_vec	**compute_camera_basis(t_cam *cam)
{
	t_vec	*w;
	t_vec	*u;
	t_vec	*v;
	t_vec	**basis;
	t_vec	*tmp;

	w = vec_negate(cam->dir);
	u = vec_cross(cam->up, w);
	tmp = vec_cross(u, w);
	v = vec_unit(tmp);
	free(tmp);
	basis = (t_vec **)malloc(sizeof(t_vec *) * 3);
	if (!basis)
		return (NULL);
	basis[0] = w;
	basis[1] = u;
	basis[2] = v;
	return (basis);
}

t_vec	*compute_upper_left_corner(t_cam *cam, double foc, t_vec *u, t_vec *v)
{
	t_vec	*tmp;
	t_vec	*tmp2;
	t_vec	*tmp3;
	t_vec	*upper_left_corner;

	tmp = vec_mult_num(cam->dir, -foc);
	tmp2 = vec_sub(cam->pos, tmp);
	free(tmp);
	tmp = vec_div_num(u, 2.0);
	tmp3 = vec_sub(tmp2, tmp);
	free(tmp);
	free(tmp2);
	tmp = vec_div_num(v, 2.0);
	upper_left_corner = vec_sub(tmp3, tmp);
	free(tmp);
	free(tmp3);
	return (upper_left_corner);
}

t_vec	*compute_pixel_00(t_vec *ulc, t_vec *d_u, t_vec *d_v)
{
	t_vec	*pixel_00;
	t_vec	*tmp1;
	t_vec	*tmp2;
	t_vec	*tmp3;

	tmp1 = vec_mult_num(d_u, 0.5);
	tmp2 = vec_mult_num(d_v, 0.5);
	tmp3 = vec_add(tmp1, tmp2);
	pixel_00 = vec_add(ulc, tmp3);
	free(tmp1);
	free(tmp2);
	free(tmp3);
	return (pixel_00);
}

t_viewport	*init_viewport(t_cam *cam)
{
	t_viewport	*viewport;
	t_vec		**basis;

	viewport = (t_viewport *)malloc(sizeof(t_viewport));
	if (!viewport)
		return (NULL);
	basis = compute_camera_basis(cam);
	viewport->height = 2.0;
	viewport->width = viewport->height * ((double)WINX / (double)WINY);
	viewport->focal_length = 2.0 * atan(100 / (cam->fov * 2.0));
	viewport->u = vec_mult_num(basis[1], viewport->width);
	viewport->v = vec_mult_num(basis[2], viewport->height);
	viewport->d_u = vec_new(viewport->u->x / WINX,
			viewport->u->y / WINX, viewport->u->z / WINX);
	viewport->d_v = vec_new(viewport->v->x / WINY,
			viewport->v->y / WINY, viewport->v->z / WINY);
	viewport->upper_left_corner = compute_upper_left_corner(cam,
			viewport->focal_length, viewport->u, viewport->v);
	viewport->p_pixel_00 = compute_pixel_00(viewport->upper_left_corner,
			viewport->d_u, viewport->d_v);
	vec_free(basis[0]);
	vec_free(basis[1]);
	vec_free(basis[2]);
	free(basis);
	return (viewport);
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
	pixel_center = vec_add(v->p_pixel_00, tmp3);
	free(tmp1);
	free(tmp2);
	free(tmp3);
	return (pixel_center);
}
