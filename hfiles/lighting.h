/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:56:56 by aramon            #+#    #+#             */
/*   Updated: 2023/09/08 12:55:40 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H

# define LIGHTING_H

# include "vector.h"

typedef struct	s_lighting
{
	t_vec		*light_pos;
	double		intensity;
	double		ambient_intensity;
}				t_lighting;

t_lighting		*init_lighting(t_list *objects);

#endif