/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:35:13 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 16:50:35 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_pos   *vec_add_pos(t_vec *v1, t_vec *v2)
{
    t_pos   *pos;

    pos = point_new(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
    return (pos);
}

t_vec   *pos_add_vec(t_pos *p1, t_pos *p2)
{
    t_vec   *vec;
    vec = vec_new(p1->x + p2->x, p1->y + p2->y, p1->z + p2->z);
    return (vec);
}

t_vec   *vec_mult_pos_num(t_pos *pos, int n)
{
    t_vec   *vec;

    vec = vec_new(pos->x * n, pos->y * n, pos->z * n);
    return (vec);
}

t_vec   *vec_add_pos_vec(t_pos *pos, t_vec *vec)
{
    t_vec   *new_vec;

    new_vec = vec_new(pos->x + vec->x, pos->y + vec->y, pos->z + vec->z);
    return (new_vec);
}