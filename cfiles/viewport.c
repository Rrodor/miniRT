/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:19:22 by aramon            #+#    #+#             */
/*   Updated: 2023/08/26 18:32:05 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "miniRT.h"

t_vec   *get_pixel_center(int x, int y)
{
    double  viewport_height;
    double  viewport_width;
    t_vec   *viewport_u;
    t_vec   *viewport_v;
    t_vec   *pixel_delta_u;
    t_vec   *pixel_delta_v;

    // Based on image resolution, define the viewport ratio
    viewport_height = 2.0;
    viewport_width = viewport_height * (WINX / WINY);

    // Based on viewport ratio and image resolution, define the viewport vectors
    viewport_u = vec_new(viewport_width, 0, 0);
    viewport_v = vec_new(0, viewport_height, 0);

    // Based on image resolution and viewport vectors, define the space between each pixel
    pixel_delta_u = vec_new(viewport_u->x / WINX, viewport_u->y / WINX, viewport_u->z / WINX);
    pixel_delta_v = vec_new(viewport_v->x / WINY, viewport_v->y / WINY, viewport_v->z / WINY);

    // Get the upper left viewport pixel
    t_vec   *camera_center = vec_new(0, 0, 0);
    t_vec   *focal_length = vec_new(0, 0, 1);
    t_vec   *viewport_upper_left_corner = vec_sub(vec_sub(vec_sub(camera_center, focal_length), vec_div_num(viewport_u, 2.0)), vec_div_num(viewport_v, 2.0));
    t_vec   *pixel_00_pos = vec_add(viewport_upper_left_corner, vec_mult_num(vec_add(pixel_delta_u, pixel_delta_v), 0.5));

	//printf("viewport_u : %f %f %f\n", viewport_u->x, viewport_u->y, viewport_u->z);
	//printf("pixel_delta_u: %f %f %f\n", pixel_delta_u->x, pixel_delta_u->y, pixel_delta_u->z);
	//printf("viewport_upper_left_corner: %f %f %f\n", viewport_upper_left_corner->x, viewport_upper_left_corner->y, viewport_upper_left_corner->z);
	//printf("pixel_00_pos: %f %f %f\n", pixel_00_pos->x, pixel_00_pos->y, pixel_00_pos->z);
    return (vec_add(pixel_00_pos, vec_add(vec_mult_num(pixel_delta_u, x), vec_mult_num(pixel_delta_v, y))));
}
