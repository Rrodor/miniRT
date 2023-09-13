/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:26:16 by aramon            #+#    #+#             */
/*   Updated: 2023/09/13 05:26:38 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "ray.h"
#include "color.h"
#include "viewport.h"

void	free_data_progress(t_vars *vars)
{
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
	t_rgb	*rgb;

	p_pixel_center = get_pixel_center(vars->viewport, x, y);
	t_vec	*tmp = vec_sub(p_pixel_center, vars->cam->pos);
	v_ray_dir = vec_unit(tmp);
	free(tmp);
	ray = ray_new(vars->cam->pos, v_ray_dir, 0);
	//rgb = get_color(vars->lighting, ray, &(vars->objs));
	rgb = get_color(&vars, ray);
	img_pix_put(&vars->img, x, y, encode_rgb(rgb));
	free(rgb);
	free(p_pixel_center);
	free(v_ray_dir);
	ray_free(ray);
}

int	render(t_vars *vars)
{
	int		y;
	int		x;

	if (vars->win == NULL)
		return (1);
	y = 0;
	while (y < WINY)
	{
		x = 0;
		while (x < WINX)
		{
			draw(vars, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
