/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabtoobj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:51:12 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/07 16:02:38 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*tabtoobj(char **tab)
{
	if (ft_strncmp(tab[0], "A", 1) == 0)
		return ((void *)tabtoamb(tab));
	if (ft_strncmp(tab[0], "C", 1) == 0)
		return ((void *)tabtocam(tab));
	if (ft_strncmp(tab[0], "L", 1) == 0)
		return ((void *)tabtolight(tab));
	if (ft_strncmp(tab[0], "sp", 1) == 0)
		return ((void *)tabtosphere(tab));
	if (ft_strncmp(tab[0], "pl", 1) == 0)
		return ((void *)tabtoplane(tab));
	if (ft_strncmp(tab[0], "cy", 1) == 0)
		return ((void *)tabtocylinder(tab));
	return (NULL);
}

t_a	*tabtoamb(char **tab)
{
	t_a		*amb;
	char	**tmp;

	amb = malloc(sizeof(t_a));
	amb->id = ft_strdup("A");
	amb->ratio = ft_atof(tab[1]);
	tmp = ft_split(tab[2], ',');
	amb->color = malloc(sizeof(t_rgb));
	amb->color->r = ft_atoi(tmp[0]);
	amb->color->g = ft_atoi(tmp[1]);
	amb->color->b = ft_atoi(tmp[2]);
	freetab(tmp);
	freetab(tab);
	return (amb);
}

t_cam	*tabtocam(char **tab)
{
	t_cam	*cam;
	char	**tmp;

	cam = malloc(sizeof(t_cam));
	cam->id = ft_strdup("C");
	tmp = ft_split(tab[1], ',');
	cam->pos = vec_new(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	freetab(tmp);
	tmp = ft_split(tab[2], ',');
	cam->dir = vec_new(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	freetab(tmp);
	cam->fov = ft_atof(tab[3]);
	freetab(tab);
	return (cam);
}

t_l	*tabtolight(char **tab)
{
	t_l		*light;
	char	**tmp;

	light = malloc(sizeof(t_l));
	light->id = ft_strdup("L");
	tmp = ft_split(tab[1], ',');
	light->pos = vec_new(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	freetab(tmp);
	light->ratio = ft_atof(tab[2]);
	tmp = ft_split(tab[3], ',');
	light->color = malloc(sizeof(t_rgb));
	light->color->r = ft_atoi(tmp[0]);
	light->color->g = ft_atoi(tmp[1]);
	light->color->b = ft_atoi(tmp[2]);
	freetab(tmp);
	freetab(tab);
	return (light);
}
