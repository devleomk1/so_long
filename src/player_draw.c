/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 07:09:00 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/05 10:35:11 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*get_player_sprimg(t_game *game, int dir)
{
	t_img	*spr;

	if (game->player.spr.frame == 1)
		spr = &(game->player.spr.imgx[dir][1]);
	else if (game->player.spr.frame == 3)
		spr = &(game->player.spr.imgx[dir][2]);
	else
		spr = &(game->player.spr.imgx[dir][0]);
	return (spr);
}

static
void	draw_player_walk(t_game *game, t_spr *player, t_img *sprite, int dir)
{
	int	x;
	int	y;

	game->flag.held_keys = TRUE;
	x = (player->x0 * TILE_SIZE)
		+ (game->dir2coord[dir].x * player->i * player->move);
	y = ((player->y0 - 1) * TILE_SIZE)
		+ (game->dir2coord[dir].y * player->i * player->move);
	ft_put_img(game, sprite->ptr, x, y);
	player->i += PLAYER_SPEED;
	if (player->i >= 64)
	{
		player->i = 0;
		game->player.spr.frame++;
		game->flag.held_keys = FALSE;
		game->flag.player_walk = FALSE;
	}
}

void	draw_player(t_game *game)
{
	int		dir;
	t_spr	*player;
	t_img	*sprite;

	dir = game->player.spr.dir;
	player = &(game->player.spr);
	sprite = get_player_sprimg(game, dir);
	if (game->flag.player_walk)
		draw_player_walk(game, player, sprite, dir);
	else
		ft_put_img64(game, sprite->ptr, player->x, player->y - 1);
}

void	draw_enemy(t_game *game)
{
	ft_put_img64(game, game->enemy.img0.ptr, game->enemy.x, game->enemy.y - 1);
}
