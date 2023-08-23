/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:37:05 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 12:13:06 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

void    vec_copy(t_vec *dst, t_vec *src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

void    vec_free(t_vec *vec)
{
    if (!vec)
        return ;
    free(vec);
}

t_vec   *vec_unit(t_vec *v)
{
    return (vec_div_num(v, vec_len(v)));
}

double  vec_dot(t_vec *v1, t_vec *v2)
{
    return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}