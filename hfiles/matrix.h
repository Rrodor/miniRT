/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:54:47 by aramon            #+#    #+#             */
/*   Updated: 2023/09/11 20:54:47 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H

# define MATRIX_H

# include "vector.h"

typedef struct s_mat
{
    t_vec   *x;
    t_vec   *y;
    t_vec   *z;
}				t_mat;

t_mat	*init_mat(void);
t_mat	*mat_mult(t_mat *m1, t_mat *m2);
t_vec	*mat_mult_vec(t_mat *m, t_vec *v);
t_mat   *init_x_rotation_matrix(double x_angle);
t_mat   *init_y_rotation_matrix(double y_angle);
t_mat   *init_z_rotation_matrix(double z_angle);
void    free_mat(t_mat *mat);

#endif