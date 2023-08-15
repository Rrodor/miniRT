/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:49:26 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/15 14:02:40 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rt_error(char **str)
{
	static t_point	i = {0, 0, 0};

	if (!str[0])
		return (0);
	if (ft_strncmp(str[0], "A", 1) == 0 && i.x++ == 0)
		if (error_a(str) == -1)
			return (-1);
	if (ft_strncmp(str[0], "C", 1) == 0 && i.y++ == 0)
		if (error_c(str) == -1)
			return (-1);
	if (ft_strncmp(str[0], "L", 1) == 0 && i.z++ == 0)
		if (error_l(str) == -1)
			return (-1);
	if (i.x > 1 || i.y > 1 || i.z > 1)
		return (-1);
	if (errorform(str) == -1)
		return (-1);
	return (0);
}

int	error_a(char **str)
{
	char	**tab;
	int		i;

	i = 0;
	if (tablen(str) != 3)
		return (-1);
	tab = ft_split(str[2], ',');
	if (isfloat(str[1]))
		i = -1;
	else if (ft_atof(str[1]) > 1)
		i = -1;
	else if (error_color(str[2]) == -1)
		i = -1;
	freetab(tab);
	return (i);
}

int	error_c(char **str)
{
	char	**tab;
	int		i;

	i = 0;
	if (tablen(str) != 4)
		return (-1);
	tab = ft_split(str[1], ',');
	if (tablen(tab) != 3)
		i = -1;
	else if (isfloat(tab[0]) || isfloat(tab[1]) || isfloat(tab[2]))
		i = -1;
	freetab(tab);
	if (error_vector(str[2]) == -1)
		i = -1;
	if (isfloat(str[3]))
		i = -1;
	else if (ft_atof(str[3]) > 180 || ft_atof(str[3]) < 0)
		i = -1;
	return (i);
}

int	error_l(char **str)
{
	char	**tab;
	int		i;

	i = 0;
	if (tablen(str) != 4)
		return (-1);
	tab = ft_split(str[1], ',');
	if (tablen(tab) != 3)
		i = -1;
	else if (isfloat(tab[0]) || isfloat(tab[1]) || isfloat(tab[2]))
		i = -1;
	freetab(tab);
	if (isfloat(str[2]))
		i = -1;
	else if (ft_atof(str[2]) > 1 || ft_atof(str[2]) < 0)
		i = -1;
	if (error_color(str[3]) == -1)
		i = -1;
	return (i);
}

int	error_color(char *str)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (tablen(tab) != 3)
	{
		freetab(tab);
		return (-1);
	}
	if (isfloat(tab[0]) || isfloat(tab[1]) || isfloat(tab[2]))
	{
		freetab(tab);
		return (-1);
	}
	if (ft_atof(tab[0]) < 0 || ft_atof(tab[1]) < 0 || ft_atof(tab[2]) < 0)
	{
		freetab(tab);
		return (-1);
	}
	if (ft_atof(tab[0]) > 255 || ft_atof(tab[1]) > 255 || ft_atof(tab[2]) > 255)
	{
		freetab(tab);
		return (-1);
	}
	freetab(tab);
	return (0);
}
