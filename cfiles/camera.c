/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:51:51 by aramon            #+#    #+#             */
/*   Updated: 2023/09/07 14:08:20 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "camera.h"

t_cam	*getcam(t_list *list)
{
	t_cam	*cam;
	t_list	*tmp;

	tmp = list;
	cam = (t_cam *)list->content;
	while (ft_strncmp(cam->id, "C", 1))
	{
		tmp = tmp->next;
		cam = (t_cam *)tmp->content;
	}
	return (cam);
}

void	movecam(int keycode, t_vars *vars)
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
	vars->viewport = init_viewport(vars->cam);
	render(vars);
}
