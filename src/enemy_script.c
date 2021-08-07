/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_script.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:40:23 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/07 15:58:06 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_game *game)
{
	game->enemy.dir = DIR_SOUTH;
	game->enemy.i = 0;
	game->enemy.move = TRUE;
}

void	enemy_find_player(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	dir;

	i = 0;
	dir = game->enemy.dir;
	while (!game->flag.enemy_walk)
	{
		x = game->enemy.x + game->dir2coord[dir].x * i;
		y = game->enemy.y + game->dir2coord[dir].y * i;
		if (game->maps.coord[y][x] == '1')
			return ;
		if (game->player.spr.x == x && game->player.spr.y == y)
		{
			game->flag.held_keys = TRUE;
			game->flag.enemy_walk = TRUE;
			game->enemy.x0 = game->enemy.x;
			game->enemy.y0 = game->enemy.y;
			game->enemy.x = x - game->dir2coord[dir].x;
			game->enemy.y = y - game->dir2coord[dir].y;
			return ;
		}
		i++;
	}
}

void	enemy_script(t_game *game)
{
	if (game->fps % 100 == 0 && !game->flag.enemy_walk)
		spin_clockwise(game, &(game->enemy));
	enemy_find_player(game);
}
