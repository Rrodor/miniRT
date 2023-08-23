/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:16:16 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 16:44:39 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "position.h"
#include <stdlib.h>

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