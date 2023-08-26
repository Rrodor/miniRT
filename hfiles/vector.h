/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:54:54 by aramon            #+#    #+#             */
/*   Updated: 2023/08/26 18:19:13 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

// Vector3 struct
typedef struct 	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

// vector_utils_1.c
t_vec	*vec_new(double x, double y, double z);
t_vec	*vec_add(t_vec *v1, t_vec *v2);
t_vec	*vec_sub(t_vec *v1, t_vec *v2);
t_vec	*vec_mult(t_vec *v1, t_vec *v2);
t_vec	*vec_div(t_vec *v1, t_vec *v2);

// vector_utils_2.c
t_vec	*vec_cross(t_vec *v1, t_vec *v2);
t_vec	*vec_mult_num(t_vec *v, double n);
t_vec	*vec_div_num(t_vec *v, double n);
t_vec	*vec_unit(t_vec *v);
double	vec_len(t_vec *v);

// vector_utils_3.c
void	vec_copy(t_vec *dst, t_vec *src);
void	vec_free(t_vec *vec);
double	vec_dot(t_vec *v1, t_vec *v2);
//t_vec	*vec_sub_pos(t_pos *p1, t_pos *p2);

/* vector_utils_4.c
t_pos	*vec_add_pos(t_vec *v1, t_vec *v2);
t_vec   *pos_add_vec(t_pos *p1, t_pos *p2);
t_vec   *vec_mult_pos_num(t_pos *pos, int n);*/

#endif
