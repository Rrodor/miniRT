/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabtoform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:04:34 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/14 15:05:47 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	freetab(tmp);
	sphere->radius = ft_atof(tab[2]);
	tmp = ft_split(tab[3], ',');
	sphere->color.r = ft_atoi(tmp[0]);
	sphere->color.g = ft_atoi(tmp[1]);
	sphere->color.b = ft_atoi(tmp[2]);
	freetab(tmp);
	freetab(tab);
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
	freetab(tmp);
	tmp = ft_split(tab[2], ',');
	cylinder->dir.x = ft_atof(tmp[0]);
	cylinder->dir.y = ft_atof(tmp[1]);
	cylinder->dir.z = ft_atof(tmp[2]);
	freetab(tmp);
	cylinder->diameter = ft_atof(tab[3]);
	cylinder->height = ft_atof(tab[4]);
	tmp = ft_split(tab[5], ',');
	cylinder->color.r = ft_atoi(tmp[0]);
	cylinder->color.g = ft_atoi(tmp[1]);
	cylinder->color.b = ft_atoi(tmp[2]);
	freetab(tmp);
	freetab(tab);
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
	freetab(tmp);
	tmp = ft_split(tab[2], ',');
	plane->dir.x = ft_atof(tmp[0]);
	plane->dir.y = ft_atof(tmp[1]);
	plane->dir.z = ft_atof(tmp[2]);
	freetab(tmp);
	tmp = ft_split(tab[3], ',');
	plane->color.r = ft_atoi(tmp[0]);
	plane->color.g = ft_atoi(tmp[1]);
	plane->color.b = ft_atoi(tmp[2]);
	freetab(tmp);
	freetab(tab);
	return (plane);
}
