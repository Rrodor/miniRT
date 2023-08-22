/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:59:24 by aramon            #+#    #+#             */
/*   Updated: 2023/08/22 09:10:10 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec    *vec_cross(t_vec *v1, t_vec *v2)
{
    return (vec_new(v1->y * v2->z - v1->z * v2->y,
                    v1->z * v2->x - v1->x * v2->z,
                    v1->x * v2->y - v1->y * v2->x));
}

t_vec   *vec_mult_num(t_vec *v, double n)
{
    return (vec_new(v->x * n, v->y * n, v->z * n));
}

t_vec   *vec_div_num(t_vec *v, double n)
{
    return (vec_new(v->x / n, v->y / n, v->z / n));
}

t_vec   *vec_unit(t_vec *v)
{
    return (vec_div_num(v, vec_len(v)));
}

double   vec_len(t_vec *v)
{
    return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
}