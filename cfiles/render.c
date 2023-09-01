/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:26:16 by aramon            #+#    #+#             */
/*   Updated: 2023/08/31 16:17:44 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "ray.h"
#include "color.h"
#include "viewport.h"

/*
	1. progress() can be added somewhere else
	2. free_data_progress() can be added somewhere else
	3. Segfault on free_data_progress() need to be fixed
	4. img_pix_put peut degager sur color.c
*/

void	free_data_progress(t_vars *vars)
{
	//free(vars->img_progress.addr); <<--- Segfault if free this shit
	mlx_destroy_image(vars->mlx, vars->img_progress.img);
}

void	img_pix_put(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	progress(t_vars *vars, double curr_x, int color)
{
	int	i;
	int	bar_size;

	i = 0;
	bar_size = 10;
	while (i < bar_size)
	{
		img_pix_put(&vars->img_progress, curr_x, i, color);
		i++;
	}
}

void	draw(t_vars *vars, int x, int y)
{
	t_vec	*v_ray_dir;
	t_vec	*p_pixel_center;
	t_ray	*ray;

	p_pixel_center = get_pixel_center(vars->viewport, x, y);
	v_ray_dir = vec_new(p_pixel_center->x, p_pixel_center->y, p_pixel_center->z);
	ray = ray_new(vec_new(0, 0, 0), v_ray_dir);
	img_pix_put(&vars->img, x, y, encode_rgb(get_color(ray, vars->objs)));
	free(v_ray_dir);
	free(p_pixel_center);
	free(ray);
}

int	render(t_vars *vars)
{
	int		y;
	int		x;
	int		pixels_drawn;
	int		total_pixels;

	if (vars->win == NULL)
		return (1);
	pixels_drawn = 0;
	total_pixels = WINX * WINY;
	y = 0;
	while (y < WINY)
	{
		x = 0;
		while (x < WINX)
		{
			progress(vars, (double)pixels_drawn++ / (total_pixels) * WINX, GREEN);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_progress.img, 0, 0);
			draw(vars, x, y);
			x++;
		}
		y++;
	}
	free_data_progress(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
