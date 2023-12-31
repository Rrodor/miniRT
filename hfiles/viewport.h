/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:30:20 by aramon            #+#    #+#             */
/*   Updated: 2023/09/13 15:26:54 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H

# define VIEWPORT_H

typedef struct s_vec	t_vec;

typedef struct s_viewport
{
	double		width;
	double		height;
	double		focal_length;
	t_vec		*u;
	t_vec		*v;
	t_vec		*d_u;
	t_vec		*d_v;
	t_vec		*upper_left_corner;
	t_vec		*p_pixel_00;
}				t_viewport;

t_viewport		*init_viewport(t_cam *cam);
void			free_viewport(t_viewport *viewport);
t_vec			*get_pixel_center(t_viewport *viewport, int x, int y);

#endif
