/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 05:54:32 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/06 12:15:04 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_dir(t_game *game, t_spr *sprite, int dir)
{
	sprite->x0 = sprite->x;
	sprite->y0 = sprite->y;
	sprite->dir = dir;
	if (sprite->frame > sprite->frame_max)
		sprite->frame = 0;
	sprite->frame++;
	if (!is_collision(game, sprite, dir))
	{
		sprite->move = TRUE;
		sprite->x += game->dir2coord[dir].x;
		sprite->y += game->dir2coord[dir].y;
		sprite->step++;
		if (sprite == &(game->player.spr))
			game->flag.step_cnt = TRUE;
	}
	else
		sprite->move = FALSE;
	game->flag.player_walk = TRUE;
}

void	move_north(t_game *game, t_spr *sprite)
{
	move_dir(game, sprite, DIR_NORTH);
}

void	move_south(t_game *game, t_spr *sprite)
{
	move_dir(game, sprite, DIR_SOUTH);
}

void	move_west(t_game *game, t_spr *sprite)
{
	move_dir(game, sprite, DIR_WEST);
}

void	move_east(t_game *game, t_spr *sprite)
{
	move_dir(game, sprite, DIR_EAST);
}
