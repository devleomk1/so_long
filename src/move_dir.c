/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 05:54:32 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/29 14:12:54 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	_move_dir(t_game *game, t_spr *sprite, int dir)
{
	if (!is_collision(game, sprite, dir))
	{
		sprite->x0 = sprite->x;
		sprite->y0 = sprite->y;
		sprite->dir = dir;
		sprite->x += game->dir2coord[dir].x;
		sprite->y += game->dir2coord[dir].y;
		sprite->step++;
		if (sprite == &(game->player.spr))
		{
			game->flag.player_walk = TRUE;
			game->flag.step_cnt = TRUE;
		}
	}
	if (sprite->step % 2 == 0)
		sprite->frame ++;
	sprite->frame ++;
	if (sprite->frame > sprite->frame_max)
		sprite->frame = 0;
	return (1);
}

void	move_north(t_game *game, t_spr *sprite)
{
	_move_dir(game, sprite, DIR_NORTH);
}

void	move_south(t_game *game, t_spr *sprite)
{
	_move_dir(game, sprite, DIR_SOUTH);
}

void	move_west(t_game *game, t_spr *sprite)
{
	_move_dir(game, sprite, DIR_WEST);
}

void	move_east(t_game *game, t_spr *sprite)
{
	_move_dir(game, sprite, DIR_EAST);
}
