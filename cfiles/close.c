/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:48 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/23 12:03:31 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	win_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	//mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	if (vars->objs)
		ft_lstclear(&(vars->objs), &freelst);
	exit(0);
}
