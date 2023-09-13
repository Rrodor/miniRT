/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:56:40 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/13 15:04:36 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rot_x(t_vec *vec, t_vec *rot, int invert)
{
	t_vec	new;

	new.y = vec->y * cos(invert * rot->x) + vec->z * -sin(invert * rot->x);
	new.z = vec->y * sin(invert * rot->x) + vec->z * cos(invert * rot->x);
	vec->y = new.y;
	vec->z = new.z;
}

void	rot_y(t_vec *vec, t_vec *rot, int invert)
{
	t_vec	new;

	new.x = vec->x * cos(invert * rot->y) + vec->z * sin(invert * rot->y);
	new.z = vec->x * -sin(invert * rot->y) + vec->z * cos(invert * rot->y);
	vec->x = new.x;
	vec->z = new.z;
}

void	rot_z(t_vec *vec, t_vec *rot, int invert)
{
	t_vec	new;

	new.x = vec->x * cos(invert * rot->z) + vec->y * -sin(invert * rot->z);
	new.y = vec->x * sin(invert * rot->z) + vec->y * cos(invert * rot->z);
	vec->x = new.x;
	vec->y = new.y;
}

void	rot(t_vec *vec, t_vec *rot, int invert)
{
	if (invert == -1)
	{
		rot_x(vec, rot, invert);
		rot_y(vec, rot, invert);
		rot_z(vec, rot, invert);
	}
	else
	{
		rot_z(vec, rot, invert);
		rot_y(vec, rot, invert);
		rot_x(vec, rot, invert);
	}
}
