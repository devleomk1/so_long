/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:01:18 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/07 16:04:13 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*get_enemy_sprimg(t_game *game, int dir)
{
	t_img	*spr;

	if (game->enemy.frame == 1)
		spr = &(game->enemy.imgx[dir][1]);
	else if (game->enemy.frame == 3)
		spr = &(game->enemy.imgx[dir][2]);
	else
		spr = &(game->enemy.imgx[dir][0]);
	return (spr);
}

void	draw_enemy_walk(t_game *game, t_spr *enemy, t_img *sprite, int dir)
{
	int	x;
	int	y;

	game->flag.held_keys = TRUE;
	x = (enemy->x0 * TILE_SIZE)
		+ (game->dir2coord[dir].x * enemy->i);
	y = ((enemy->y0 - 1) * TILE_SIZE)
		+ (game->dir2coord[dir].y * enemy->i);
	ft_put_img(game, sprite->ptr, x, y);
	enemy->i += ENEMY_SPEED;
	if (enemy->x * TILE_SIZE == x && (enemy->y - 1) * TILE_SIZE == y)
	{
		enemy->i = 0;
		game->flag.held_keys = FALSE;
		game->flag.enemy_walk = FALSE;
		game->flag.game_over = TRUE;
	}
}

void	draw_enemy(t_game *game)
{
	int		dir;
	t_spr	*enemy;
	t_img	*sprite;

	dir = game->enemy.dir;
	enemy = &(game->enemy);
	sprite = get_enemy_sprimg(game, dir);
	if (game->flag.enemy_walk && !game->flag.player_walk)
		draw_enemy_walk(game, enemy, sprite, dir);
	else
		ft_put_img64(game, sprite->ptr, enemy->x0, enemy->y0 - 1);

}
