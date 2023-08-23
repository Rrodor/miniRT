/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:19:22 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 12:04:11 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "position.h"
#include "vector.h"
#include "miniRT.h"

t_pos   *get_pixel_center(int x, int y)
{
    t_pos   pixel_center_pos;
    double  viewport_height;
    double  viewport_width;
    t_vec   *viewport_u;
    t_vec   *viewport_v;
    t_pos   *pixel_delta_u;
    t_pos   *pixel_delta_v;

    // Based on image resolution, define the viewport ratio
    viewport_height = 2.0;
    viewport_width = viewport_height * (WINX / WINY);

    // Based on viewport ratio and image resolution, define the viewport vectors
    viewport_u = new_vec(viewport_width, 0, 0);
    viewport_v = new_vec(0, viewport_height, 0);

    // Based on image resolution and viewport vectors, define the space between each pixel
    pixel_delta_u = new_pos(viewport_u->x / WINX, viewport_u->y / WINX, viewport_u->z / WINX);
    pixel_delta_v = new_pos(viewport_v->x / WINY, viewport_v->y / WINY, viewport_v->z / WINY);

    // Get the upper left viewport pixel
    t_pos   *camera_center = point_new(0, 0, 0);
    t_vec   *focal_length = vec_new(0, 0, 1);
    t_vec   *viewport_upper_left_corner = vec_sub(vec_sub(vec_sub(camera_center, focal_length), vec_div(viewport_u, 2)), vec_div(viewport_v, 2));
    t_pos   *pixel_00_pos = vec_add_num(viewport_upper_left_corner, vec_mult_num(vec_add(pixel_delta_u, pixel_delta_v), 0.5));

    return (vec_add(pixel_00_pos, vec_add(vec_mult_num(pixel_delta_u, x), vec_mult_num(pixel_delta_v, y))));
}