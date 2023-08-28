/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:50 by aramon            #+#    #+#             */
/*   Updated: 2023/08/27 10:07:03 by aramon           ###   ########.fr       */
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

t_rgb			*init_color(int r, int g, int b);
t_rgb			*get_color(t_ray *ray);
int				encode_rgb(t_rgb *rgb);

#endif