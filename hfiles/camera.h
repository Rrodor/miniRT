/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:52:44 by aramon            #+#    #+#             */
/*   Updated: 2023/09/06 17:39:16 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H

# define CAMERA_H

# include "vector.h"
# include "miniRT.h"

typedef struct s_cam
{
	char		*id;
	t_vec		*pos;
	t_vec		*dir;
	float		fov;
}				t_cam;

t_cam	*init_cam(void);
t_cam	*getcam(t_list *list);

#endif
