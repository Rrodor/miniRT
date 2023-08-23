/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:50 by aramon            #+#    #+#             */
/*   Updated: 2023/08/22 21:13:48 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H

# define COLOR_H

#include "ray.h"

typedef struct	s_rgb
{
    int			r;
    int			g;
    int			b;
}				t_rgb;

t_rgb		    *init_color(int r, int g, int b);
t_rgb           *ray_color(t_ray *ray);

#endif