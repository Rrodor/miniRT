/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:54:54 by aramon            #+#    #+#             */
/*   Updated: 2023/09/06 17:39:30 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

// Vector3 struct
typedef struct s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

// vector_utils_1.c
t_vec			*vec_new(double x, double y, double z);
t_vec			*vec_add(t_vec *v1, t_vec *v2);
t_vec			*vec_sub(t_vec *v1, t_vec *v2);
t_vec			*vec_mult(t_vec *v1, t_vec *v2);
t_vec			*vec_div(t_vec *v1, t_vec *v2);

// vector_utils_2.c
t_vec			*vec_add_num(t_vec *v, double n);
t_vec			*vec_sub_num(t_vec *v, double n);
t_vec			*vec_mult_num(t_vec *v, double n);
t_vec			*vec_div_num(t_vec *v, double n);

// vector_utils_3.c
void			vec_copy(t_vec *dst, t_vec *src);
void			vec_free(t_vec *vec);
double			vec_dot(t_vec *v1, t_vec *v2);
t_vec			*vec_cross(t_vec *v1, t_vec *v2);
t_vec			*vec_unit(t_vec *v);
double			vec_len(t_vec *v);

#endif
