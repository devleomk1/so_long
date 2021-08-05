/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 07:18:32 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/05 10:02:05 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	tile_img_init(t_game *game)
{
	game->tile.t0.ptr = ft_xpm_to_img(game, "tile00.xpm");
	game->tile.t1.ptr = ft_xpm_to_img(game, "tile01.xpm");
	game->tile.tl.ptr = ft_xpm_to_img(game, "ladder.xpm");
	game->tile.tb.ptr = ft_xpm_to_img(game, "num_box_16.xpm");
	game->tile.ts.ptr = ft_xpm_to_img(game, "stone.xpm");
	game->tile.nl.ptr = ft_xpm_to_img(game, "black.xpm");
}

static void	player_img_init(t_game *game)
{
	game->player.spr.img0.ptr = ft_xpm_to_img(game, "player_fr.xpm");
	game->player.spr.imgx[DIR_NORTH][0].ptr = ft_xpm_to_img(game, "player_N00.xpm");
	game->player.spr.imgx[DIR_NORTH][1].ptr = ft_xpm_to_img(game, "player_N01.xpm");
	game->player.spr.imgx[DIR_NORTH][2].ptr = ft_xpm_to_img(game, "player_N02.xpm");
	game->player.spr.imgx[DIR_SOUTH][0].ptr = ft_xpm_to_img(game, "player_S00.xpm");
	game->player.spr.imgx[DIR_SOUTH][1].ptr = ft_xpm_to_img(game, "player_S01.xpm");
	game->player.spr.imgx[DIR_SOUTH][2].ptr = ft_xpm_to_img(game, "player_S02.xpm");
	game->player.spr.imgx[DIR_WEST][0].ptr = ft_xpm_to_img(game, "player_W00.xpm");
	game->player.spr.imgx[DIR_WEST][1].ptr = ft_xpm_to_img(game, "player_W01.xpm");
	game->player.spr.imgx[DIR_WEST][2].ptr = ft_xpm_to_img(game, "player_W02.xpm");
	game->player.spr.imgx[DIR_EAST][0].ptr = ft_xpm_to_img(game, "player_E00.xpm");
	game->player.spr.imgx[DIR_EAST][1].ptr = ft_xpm_to_img(game, "player_E01.xpm");
	game->player.spr.imgx[DIR_EAST][2].ptr = ft_xpm_to_img(game, "player_E02.xpm");
	game->player.spr.img1.ptr = ft_xpm_to_img(game, "player01.xpm");
	game->player.spr.img2.ptr = ft_xpm_to_img(game, "player02.xpm");
	game->enemy.img0.ptr = ft_xpm_to_img(game, "rocket00.xpm");
}

static void	etc_img_init(t_game *game)
{
	game->gameover.ptr = ft_xpm_to_img(game, "gameover.xpm");
	game->ending.ptr = ft_xpm_to_img(game, "ending.xpm");
	game->pika.img0.ptr = ft_xpm_to_img(game, "loading0.xpm");
	game->pika.img1.ptr = ft_xpm_to_img(game, "loading1.xpm");
	game->collec.ball.ptr = ft_xpm_to_img(game, "ball.xpm");

}

void	init_img(t_game *game)
{
	tile_img_init(game);
	player_img_init(game);
	etc_img_init(game);
}
