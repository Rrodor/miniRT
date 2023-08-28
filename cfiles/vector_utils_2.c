/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:59:24 by aramon            #+#    #+#             */
/*   Updated: 2023/08/28 14:21:45 by aramon           ###   ########.fr       */
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

