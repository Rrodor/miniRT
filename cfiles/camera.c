/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:51:51 by aramon            #+#    #+#             */
/*   Updated: 2023/09/13 15:23:11 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "camera.h"

t_cam	*get_cam(t_list *list)
{
	t_cam	*cam;
	t_list	*tmp;
	t_vec	*world_up;

	tmp = list;
	cam = (t_cam *)list->content;
	while (ft_strncmp(cam->id, "C", 1))
	{
		tmp = tmp->next;
		cam = (t_cam *)tmp->content;
	}
	world_up = vec_new(0, 1, 0);
	cam->right = vec_cross(world_up, cam->dir);
	cam->up = vec_cross(cam->dir, cam->right);
	free(world_up);
	return (cam);
}

void	cam_rotation(int keycode, t_vars *vars)
{
	t_vec	*rot_angle;

	rot_angle = vec_new(0.0, 0.0, 0.0);
	if (keycode == KEY_L)
		rot_angle->y = 0.1;
	else if (keycode == KEY_J)
		rot_angle->y = -0.1;
	else if (keycode == KEY_I)
		rot_angle->x = 0.1;
	else if (keycode == KEY_K)
		rot_angle->x = -0.1;
	else if (keycode == KEY_O)
		rot_angle->z = 0.1;
	else if (keycode == KEY_U)
		rot_angle->z = -0.1;
	rot(vars->cam->dir, rot_angle, 1);
	free(rot_angle);
}

void	cam_movement(int keycode, t_vars *vars)
{
	if (keycode == KEY_UP)
		vars->cam->pos->y += 0.1;
	else if (keycode == KEY_DOWN)
		vars->cam->pos->y -= 0.1;
	else if (keycode == KEY_LEFT)
		vars->cam->pos->x -= 0.1;
	else if (keycode == KEY_RIGHT)
		vars->cam->pos->x += 0.1;
	else if (keycode == KEY_Q)
		vars->cam->pos->z -= 0.1;
	else if (keycode == KEY_A)
		vars->cam->pos->z += 0.1;
	else if (keycode == KEY_F || keycode == KEY_R)
	{
		if (keycode == KEY_F)
			vars->cam->fov += 5;
		else
			vars->cam->fov -= 5;
	}
	if (keycode == KEY_J || keycode == KEY_L ||
		keycode == KEY_I || keycode == KEY_K ||
		keycode == KEY_O || keycode == KEY_U)
		cam_rotation(keycode, vars);
	free_viewport(vars->viewport);
	vars->viewport = init_viewport(vars->cam);
	render(vars);
}

void	free_cam(t_cam *cam)
{
	free(cam->right);
	free(cam->up);
}
