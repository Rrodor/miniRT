/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:52:44 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 11:55:18 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H

# define CAMERA_H

#include "vector.h"
#include "position.h"

typedef struct	s_cam
{
	char		*id; // Why ?
	t_pos		pos;
	t_vec		dir;
	float		fov;
}				t_cam;

t_cam   *init_cam();

#endif