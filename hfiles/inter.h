/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:33:13 by aramon            #+#    #+#             */
/*   Updated: 2023/09/06 17:30:13 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_H
# define INTER_H

struct	s_ray;
struct	s_vec;

// intersection
typedef struct s_inter
{
	t_ray		*ray;
	double		t;
}				t_inter;

void			inter_new(t_inter *inter, t_ray *ray);
void			inter_copy(t_inter *dst, t_inter *src);
t_vec			*inter_pos(t_inter *inter);

#endif
