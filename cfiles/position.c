/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:16:16 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 17:04:31 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "position.h"
#include <stdlib.h>

typedef struct s_vec t_vec;

t_pos		*point_new(double x, double y, double z)
{
    t_pos   *pos;

    pos = (t_pos *)malloc(sizeof(t_pos));
    if (!pos)
        return (NULL);
    pos->x = x;
    pos->y = y;
    pos->z = z;
    return (pos);
}

t_pos   *vec_add_pos_vec(t_pos *pos, t_vec *vec)
{
    t_pos   *new_pos;

    new_pos = point_new(pos->x + vec->x, pos->y + vec->y, pos->z + vec->z);
    return (new_pos);
}