/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:58:50 by aramon            #+#    #+#             */
/*   Updated: 2023/09/07 18:14:56 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

t_vec	*vec_new(double x, double y, double z)
{
	t_vec	*vec;

	vec = (t_vec *)malloc(sizeof(t_vec));
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vec	*vec_add(t_vec *v1, t_vec *v2)
{
	return (vec_new(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z));
}

t_vec	*vec_sub(t_vec *v1, t_vec *v2)
{
	return (vec_new(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z));
}

t_vec	*vec_mult(t_vec *v1, t_vec *v2)
{
	return (vec_new(v1->x * v2->x, v1->y * v2->y, v1->z * v2->z));
}

t_vec	*vec_div(t_vec *v1, t_vec *v2)
{
	return (vec_new(v1->x / v2->x, v1->y / v2->y, v1->z / v2->z));
}
