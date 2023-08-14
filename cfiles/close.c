/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:48 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/13 19:01:05 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*void	freetab(void *content)
{
	int	i;

	i = 0;
	while (((char **)content)[i])
	{
		ft_printf("free %s\n", ((char **)content)[i]);
		free(((char **)content)[i]);
		i++;
	}
	free(content);
}*/

void	freelst(void *content)
{
	t_a *a;

	a = (t_a *)content;
	if (a->id == "A")
		free(obj->obj.sp);
	if (a->id == "C")
		free(obj->obj.pl);
	if (a->id == "L")
	if (a->id == "")
	if (a->id == "")
	if (a->id == "")
}

int	win_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_lstclear(&(vars->objs), &freelst);
	exit(0);
}
