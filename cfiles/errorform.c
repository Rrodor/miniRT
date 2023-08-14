/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:22:47 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/13 16:23:04 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	errorform(char **str)
{
	if (ft_strcmp(str[0], "sp") == 0)
		if (error_sp(str) == -1)
			return (-1);
	if (ft_strcmp(str[0], "pl") == 0)
		if (error_pl(str) == -1)
			return (-1);
	if (ft_strcmp(str[0], "sq") == 0)
		if (error_sq(str) == -1)
			return (-1);
	if (ft_strcmp(str[0], "cy") == 0)
		if (error_cy(str) == -1)
			return (-1);
	return (0);
}
