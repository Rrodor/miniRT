/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:26:16 by aramon            #+#    #+#             */
/*   Updated: 2023/08/22 18:34:50 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int render(t_vars *vars)
{
    if (vars->win != NULL)
        mlx_pixel_put(vars->mlx, vars->win, 100, 100, 0x00FF0000);
    return (0);
}