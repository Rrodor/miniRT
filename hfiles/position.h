/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:14:20 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 16:57:39 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H

# define POINT_H

// position
typedef struct s_pos
{
	double	x;
	double	y;
	double	z;
}				t_pos;

t_pos		*point_new(double x, double y, double z);
t_pos		*vec_add_pos_vec(t_pos *pos, t_vec *vec);

#endif