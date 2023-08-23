/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:35:13 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 16:35:58 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "position.h"

t_pos   *vec_add_pos(t_vec *v1, t_vec *v2)
{
    t_pos   *pos;

    pos = point_new(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
    return (pos);
}