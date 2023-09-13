/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:48 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/13 14:45:54 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	win_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, vars->img_progress.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_cam(vars->cam);
	viewport_free(vars->viewport);
	if (vars->objs)
		ft_lstclear(&(vars->objs), &freelst);
	if (vars->lighting)
		free(vars->lighting);
	exit(0);
}

int	objreq(t_list *list)
{
	int		cam;
	int		amb;
	int		light;
	t_list	*tmp;

	cam = 0;
	amb = 0;
	light = 0;
	tmp = list;
	while (tmp)
	{
		if (!ft_strncmp(((t_a *)tmp->content)->id, "C", 1))
			cam++;
		if (!ft_strncmp(((t_a *)tmp->content)->id, "A", 1))
			amb++;
		if (!ft_strncmp(((t_a *)tmp->content)->id, "L", 1))
			light++;
		tmp = tmp->next;
	}
	if (cam == 1 && amb == 1 && light == 1)
		return (0);
	ft_printf("Error\nMissing object(s)\n");
	if (list)
		ft_lstclear(&list, freelst);
	return (-1);
}
