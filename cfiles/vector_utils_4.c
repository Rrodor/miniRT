/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:03:02 by aramon            #+#    #+#             */
/*   Updated: 2023/09/13 15:03:02 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	*vec_negate(t_vec *v)
{
	t_vec	*new;

	new = vec_new(-v->x, -v->y, -v->z);
	return (new);
}
