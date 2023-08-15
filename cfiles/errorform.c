/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:22:47 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/15 14:06:30 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	errorform(char **str)
{
	if (ft_strncmp(str[0], "sp", 2) == 0)
		if (error_sp(str) == -1)
			return (-1);
	if (ft_strncmp(str[0], "pl", 2) == 0)
		if (error_pl(str) == -1)
			return (-1);
	if (ft_strncmp(str[0], "cy", 2) == 0)
		if (error_cy(str) == -1)
			return (-1);
	return (0);
}

int	error_sp(char **str)
{
	char	**tab;
	int		i;

	i = 0;
	if (tablen(str) != 4)
		return (-1);
	tab = ft_split(str[1], ',');
	if (isfloat(tab[0]) || isfloat(tab[1]) || isfloat(tab[2]))
		i = -1;
	else if (isfloat(str[2]))
		i = -1;
	else if (error_color(str[3]) == -1)
		i = -1;
	freetab(tab);
	return (i);
}

int	error_pl(char **str)
{
	char	**tab;
	int		i;

	i = 0;
	if (tablen(str) != 4)
		return (-1);
	tab = ft_split(str[1], ',');
	if (isfloat(tab[0]) || isfloat(tab[1]) || isfloat(tab[2]))
		i = -1;
	else if (error_vector(str[2]) == -1)
		i = -1;
	else if (error_color(str[3]) == -1)
		i = -1;
	freetab(tab);
	return (i);
}

int	error_cy(char **str)
{
	char	**tab;
	int		i;

	i = 0;
	if (tablen(str) != 6)
		return (-1);
	tab = ft_split(str[1], ',');
	if (isfloat(tab[0]) || isfloat(tab[1]) || isfloat(tab[2]))
		i = -1;
	else if (error_vector(str[2]) == -1)
		i = -1;
	else if (isfloat(str[3]) || isfloat(str[4]))
		i = -1;
	else if (error_color(str[5]) == -1)
		i = -1;
	freetab(tab);
	return (i);
}

int	error_vector(char *str)
{
	char	**tab;
	int		i;

	i = 0;
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
	if (ft_atof(tab[0]) < -1 || ft_atof(tab[0]) > 1)
		i = -1;
	if (ft_atof(tab[1]) < -1 || ft_atof(tab[1]) > 1)
		i = -1;
	if (ft_atof(tab[2]) < -1 || ft_atof(tab[2]) > 1)
		i = -1;
	freetab(tab);
	return (i);
}
