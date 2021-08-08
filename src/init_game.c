/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:09:39 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/08 11:50:05 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	width = game->maps.cols * TILE_SIZE;
	height = game->maps.rows * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
}

void	init_player(t_game *game)
{
	game->player.step = 0;
	game->player.item = 0;
	game->player.spr.step = 0;
	game->player.spr.frame = 0;
	game->player.spr.frame_max = P_MAX_FRAME;
	game->player.spr.i = 0;
	game->player.spr.dir = DIR_SOUTH;
	game->player.spr.move = TRUE;
	game->pika.i = 0;
}

void	init_flag(t_game *game)
{
	game->flag.collect_all = FALSE;
	game->flag.held_keys = FALSE;
	game->flag.player_walk = FALSE;
	game->flag.enemy_walk = FALSE;
	game->flag.step_cnt = FALSE;
	game->fps = 0;
}

void	init_game(t_game *game)
{
	init_window(game);
	init_dir(game);
	init_img(game);
	init_enemy(game);
	init_player(game);
	init_flag(game);
	game->flag.game_scene = GAME_START;
}
