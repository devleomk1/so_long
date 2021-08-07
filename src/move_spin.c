/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_spin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:12:32 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/06 12:15:36 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spin_clockwise(t_game *game, t_spr *sprite)
{
	int	*dir;

	dir = &(sprite->dir);
	if (*dir == DIR_NORTH)
		*dir = DIR_EAST;
	else if (*dir == DIR_SOUTH)
		*dir = DIR_WEST;
	else if (*dir == DIR_WEST)
		*dir = DIR_NORTH;
	else if (*dir == DIR_EAST)
		*dir = DIR_SOUTH;
	else
		*dir = DIR_NONE;
}
