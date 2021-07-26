/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:28:20 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/27 04:28:37 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_collision(t_game *game, t_spr *sprite, int dir)
{
	int	x;
	int	y;

	x = game->dir2coord[dir].x;
	y = game->dir2coord[dir].y;
	if (game->maps.coord[sprite->y + y][sprite->x + x] == '1')
		return (TRUE);
	return (FALSE);
}
