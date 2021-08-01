/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 07:09:00 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/31 07:22:41 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*get_player_sprimg(t_game *game)
{
	t_img	*spr;

	if (game->player.spr.frame == 1)
		spr = &(game->player.spr.img1);
	else if (game->player.spr.frame == 2)
		spr = &(game->player.spr.img2);
	else
		spr = &(game->player.spr.img0);
	return (spr);
}

static
void	draw_player_walk(t_game *game, t_spr *player, t_img *sprite, int dir)
{
	int	x;
	int	y;

	game->flag.held_keys = TRUE;
	x = (player->x0 * TILE_SIZE) + (game->dir2coord[dir].x * player->i);
	y = ((player->y0 - 1) * TILE_SIZE) + (game->dir2coord[dir].y * player->i);
	ft_put_img(game, sprite->ptr, x, y);
	player->i += PLAYER_SPEED;
	if ((x == player->x * TILE_SIZE) && (y == (player->y - 1) * TILE_SIZE))
	{
		player->i = 0;
		game->player.spr.frame = 0;
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
	sprite = get_player_sprimg(game);
	if (game->flag.player_walk)
		draw_player_walk(game, player, sprite, dir);
	else
		ft_put_img64(game, sprite->ptr, player->x, player->y - 1);
}
