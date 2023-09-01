/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:56:40 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/30 13:56:58 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	*rotation(t_vec *vec, t_vec *rot)
{
	t_vec	*new_vec;

	new_vec = vec_new(0, 0, 0);
	new_vec->x = vec->x * cos(rot->x) + vec->y * sin(rot->x);
	new_vec->y = vec->x * -sin(rot->x) + vec->y * cos(rot->x);
	new_vec->z = vec->z;
	return (new_vec);
}
