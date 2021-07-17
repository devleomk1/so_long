/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 05:54:32 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/18 03:45:20 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_dir(t_game *game)
{
	game->dir2coord[DIR_NONE] = (t_coord){0, 0};
	game->dir2coord[DIR_NORTH] = (t_coord){0, -1};
	game->dir2coord[DIR_SOUTH] = (t_coord){0, 1};
	game->dir2coord[DIR_WEST] = (t_coord){-1, 0};
	game->dir2coord[DIR_EAST] = (t_coord){1, 0};
}

int	is_collision(t_game *game, t_spr *sprite, int dir)
{
	int x;
	int y;

	x = game->dir2coord[dir].x;
	y = game->dir2coord[dir].y;
	if (game->map[sprite->y + y][sprite->x + x] == 1)
		return (TRUE);
	return (FALSE);
}

static int	_move_dir(t_game *game, t_spr *sprite, int dir)
{
	if (!is_collision(game, sprite, dir))
	{
		sprite->x += game->dir2coord[dir].x;
		sprite->y += game->dir2coord[dir].y;
		sprite->step++;
		printf("step : %d\n", sprite->step);
	}
	game->flag++;
	if (game->flag > 2)
		game->flag = 0;
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
