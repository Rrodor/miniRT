/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:44:47 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/13 17:08:22 by rrodor           ###   ########.fr       */
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

	i = 0;
	j = 0;
	nb = 0;
	while (str[i] && str[i] != '.')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
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
	return (nb);
}

