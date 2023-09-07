/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:37:05 by aramon            #+#    #+#             */
/*   Updated: 2023/09/07 18:15:46 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>
#include <math.h>

t_vec	*vec_cross(t_vec *v1, t_vec *v2)
{
	return (vec_new(v1->y * v2->z - v1->z * v2->y,
			v1->z * v2->x - v1->x * v2->z,
			v1->x * v2->y - v1->y * v2->x));
}

void	vec_copy(t_vec *dst, t_vec *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

void	vec_free(t_vec *vec)
{
	if (!vec)
		return ;
	free(vec);
}

double	vec_dot(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec	*vec_unit(t_vec *v)
{
	return (vec_div_num(v, vec_len(v)));
}
