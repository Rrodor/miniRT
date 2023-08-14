/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabtoobj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:51:12 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/13 18:16:57 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void *tabtoobj(char **tab)
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
	t_a	*amb;
	char **tmp;

	amb = malloc(sizeof(t_a));
	amb->id = ft_strdup("A");
	amb->ratio = ft_atof(tab[1]);
	tmp = ft_split(tab[2], ',');
	amb->color.r = ft_atoi(tmp[0]);
	amb->color.g = ft_atoi(tmp[1]);
	amb->color.b = ft_atoi(tmp[2]);
	free(tmp);
	free(tab);
	return (amb);
}

t_c	*tabtocam(char **tab)
{
	t_c	*cam;
	char **tmp;

	cam = malloc(sizeof(t_c));
	cam->id = ft_strdup("C");
	tmp = ft_split(tab[1], ',');
	cam->pos.x = ft_atof(tmp[0]);
	cam->pos.y = ft_atof(tmp[1]);
	cam->pos.z = ft_atof(tmp[2]);
	free(tmp);
	tmp = ft_split(tab[2], ',');
	cam->dir.x = ft_atof(tmp[0]);
	cam->dir.y = ft_atof(tmp[1]);
	cam->dir.z = ft_atof(tmp[2]);
	free(tmp);
	cam->fov = ft_atof(tab[3]);
	free(tab);
	return (cam);
}

t_l	*tabtolight(char **tab)
{
	t_l	*light;
	char **tmp;

	light = malloc(sizeof(t_l));
	light->id = ft_strdup("L");
	tmp = ft_split(tab[1], ',');
	light->pos.x = ft_atof(tmp[0]);
	light->pos.y = ft_atof(tmp[1]);
	light->pos.z = ft_atof(tmp[2]);
	free(tmp);
	light->ratio = ft_atof(tab[2]);
	tmp = ft_split(tab[3], ',');
	light->color.r = ft_atoi(tmp[0]);
	light->color.g = ft_atoi(tmp[1]);
	light->color.b = ft_atoi(tmp[2]);
	free(tmp);
	free(tab);
	return (light);
}

t_sp	*tabtosphere(char **tab)
{
	t_sp	*sphere;
	char	**tmp;

	sphere = malloc(sizeof(t_sp));
	sphere->id = ft_strdup("sp");
	tmp = ft_split(tab[1], ',');
	sphere->pos.x = ft_atof(tmp[0]);
	sphere->pos.y = ft_atof(tmp[1]);
	sphere->pos.z = ft_atof(tmp[2]);
	free(tmp);
	sphere->radius = ft_atof(tab[2]);
	tmp = ft_split(tab[3], ',');
	sphere->color.r = ft_atoi(tmp[0]);
	sphere->color.g = ft_atoi(tmp[1]);
	sphere->color.b = ft_atoi(tmp[2]);
	free(tmp);
	free(tab);
	return (sphere);
}

t_cy	*tabtocylinder(char **tab)
{
	t_cy	*cylinder;
	char	**tmp;

	cylinder = malloc(sizeof(t_cy));
	cylinder->id = ft_strdup("cy");
	tmp = ft_split(tab[1], ',');
	cylinder->pos.x = ft_atof(tmp[0]);
	cylinder->pos.y = ft_atof(tmp[1]);
	cylinder->pos.z = ft_atof(tmp[2]);
	free(tmp);
	tmp = ft_split(tab[2], ',');
	cylinder->dir.x = ft_atof(tmp[0]);
	cylinder->dir.y = ft_atof(tmp[1]);
	cylinder->dir.z = ft_atof(tmp[2]);
	free(tmp);
	cylinder->diameter = ft_atof(tab[3]);
	cylinder->height = ft_atof(tab[4]);
	tmp = ft_split(tab[5], ',');
	cylinder->color.r = ft_atoi(tmp[0]);
	cylinder->color.g = ft_atoi(tmp[1]);
	cylinder->color.b = ft_atoi(tmp[2]);
	free(tmp);
	free(tab);
	return (cylinder);
}

t_pl	*tabtoplane(char **tab)
{
	t_pl	*plane;
	char	**tmp;

	plane = malloc(sizeof(t_pl));
	plane->id = ft_strdup("pl");
	tmp = ft_split(tab[1], ',');
	plane->pos.x = ft_atof(tmp[0]);
	plane->pos.y = ft_atof(tmp[1]);
	plane->pos.z = ft_atof(tmp[2]);
	free(tmp);
	tmp = ft_split(tab[2], ',');
	plane->dir.x = ft_atof(tmp[0]);
	plane->dir.y = ft_atof(tmp[1]);
	plane->dir.z = ft_atof(tmp[2]);
	free(tmp);
	tmp = ft_split(tab[3], ',');
	plane->color.r = ft_atoi(tmp[0]);
	plane->color.g = ft_atoi(tmp[1]);
	plane->color.b = ft_atoi(tmp[2]);
	free(tmp);
	free(tab);
	return (plane);
}
