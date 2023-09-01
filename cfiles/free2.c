/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:58:57 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/31 21:27:27 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	sp_free(t_sp *sp)
{
	free(sp->id);
	free(sp->pos);
	free(sp->color);
	free(sp);
}

void	pl_free(t_pl *pl)
{
	free(pl->id);
	free(pl->pos);
	free(pl->dir);
	free(pl->color);
	free(pl);
}

void	cy_free(t_cy *cy)
{
	free(cy->id);
	free(cy->pos);
	free(cy->dir);
	free(cy->color);
	free(cy);
}
