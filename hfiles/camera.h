/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:52:44 by aramon            #+#    #+#             */
/*   Updated: 2023/09/13 14:26:29 by aramon           ###   ########.fr       */
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
	t_vec		*up;
	t_vec		*right;
	float		fov;
}				t_cam;

t_cam	*init_cam(void);
t_cam	*get_cam(t_list *list);
void	free_cam(t_cam *cam);

#endif
