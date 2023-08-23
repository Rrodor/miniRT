/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:37:05 by aramon            #+#    #+#             */
/*   Updated: 2023/08/22 20:33:42 by aramon           ###   ########.fr       */
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