/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:59:24 by aramon            #+#    #+#             */
/*   Updated: 2023/09/07 18:15:52 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec	*vec_add_num(t_vec *v, double n)
{
	return (vec_new(v->x + n, v->y + n, v->z + n));
}

t_vec	*vec_sub_num(t_vec *v, double n)
{
	return (vec_new(v->x - n, v->y - n, v->z - n));
}

t_vec	*vec_mult_num(t_vec *v, double n)
{
	return (vec_new(v->x * n, v->y * n, v->z * n));
}

t_vec	*vec_div_num(t_vec *v, double n)
{
	return (vec_new(v->x / n, v->y / n, v->z / n));
}

double	vec_len(t_vec *v)
{
	return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
}
