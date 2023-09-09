/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:55:47 by aramon            #+#    #+#             */
/*   Updated: 2023/09/08 22:34:41 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vector.h"
#include "lighting.h"

t_lighting		*init_lighting(t_list *objects)
{
	t_sp		*tmp;
	t_a			*ambient;
	t_l			*light;
	t_lighting	*data;

	data = (t_lighting *)malloc(sizeof(t_lighting));
	if (!data)
		return (NULL);
	while (objects)
	{
		tmp = (t_sp *)objects->content;
		if (ft_strncmp(tmp->id, "L", 1) == 0)
		{
			light = (t_l *)tmp;
			data->light_pos = light->pos;
			data->intensity = light->ratio;
		}
		else if (ft_strncmp(tmp->id, "A", 1) == 0)
		{
			ambient = (t_a *)tmp;
			data->ambient_intensity = ambient->ratio;
		}
		objects = objects->next;
	}
	return (data);
}