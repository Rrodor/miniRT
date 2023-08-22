/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:14:20 by aramon            #+#    #+#             */
/*   Updated: 2023/08/22 18:16:44 by aramon           ###   ########.fr       */
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

t_pos       *new_point(double x, double y, double z);

#endif