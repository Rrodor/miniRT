/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:52:44 by aramon            #+#    #+#             */
/*   Updated: 2023/08/26 18:22:20 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H

# define CAMERA_H

#include "vector.h"

typedef struct	s_cam
{
	char		*id; // Why ?
	t_vec		*pos;
	t_vec		*dir;
	float		fov;
}				t_cam;

t_cam   *init_cam();

#endif
