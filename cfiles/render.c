/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:26:16 by aramon            #+#    #+#             */
/*   Updated: 2023/08/24 16:30:09 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "position.h"
#include "ray.h"
#include "color.h"

void	img_pix_put(t_data *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(int *)pixel = color;
}

int	render(t_vars *vars)
{
    int i;
    int j;
    t_vec   *ray_dir;
    t_pos   *pixel_center;
    t_ray   *ray;

	if (vars->win == NULL)
		return (1);
    i = 0;
    while (i < WINY)
    {
        j = 0;
        while (j < WINX)
        {
            pixel_center = get_pixel_center(i, j);
			printf("pixel_center: %f %f %f\n", pixel_center->x, pixel_center->y, pixel_center->z);
            ray_dir = vec_new(pixel_center->x, pixel_center->y, pixel_center->z); // <<-- (1) See below
            ray = ray_new(vec_new(0, 0, 0), ray_dir);
			printf("ray_ori: %f %f %f\n", ray->ori->x, ray->ori->y, ray->ori->z);
            img_pix_put(&vars->img, i, j, encode_rgb(get_color(ray)));
			printf("hex rgb: %x\n", encode_rgb(get_color(ray)));
			printf("i: %d j: %d\n", i, j);
            j++;
        }
        i++;
    }
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

// (1)
// The ray direction is computed by substracting the camera_center from the pixel_center
// Since the camera_center is always at (0, 0, 0), we can just pass the pixel_center as the ray direction
// If the camera_center was not at (0, 0, 0), we would have to substract the camera_center from the pixel_center
// ray_dir = vec_new(pixel_center->x - camera_center->x, pixel_center->y - camera_center->y, pixel_center->z - camera_center->z);
