/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:44:47 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/23 12:03:26 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

float	ft_atof(char *str)
{
	float	nb;
	int		i;
	int		j;
	int		neg;

	i = 0;
	j = 0;
	nb = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] && str[i] != '.')
		nb = nb * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ft_isdigit(str[i]))
		{
			nb = nb + ((str[i] - '0') / pow(10, j + 1));
			i++;
			j++;
		}
	}
	return (nb * neg);
}

int	isfloat(char *str)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.' && p == 0)
		{
			p++;
			i++;
		}
		if (str[i] == '.' && p == 1)
			return (1);
		else if (ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}
