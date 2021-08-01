/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 07:18:32 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/31 07:19:23 by jisokang         ###   ########.fr       */
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
}

static void	player_img_init(t_game *game)
{
	game->player.spr.img0.ptr = ft_xpm_to_img(game, "player_fr.xpm");
	game->player.spr.img1.ptr = ft_xpm_to_img(game, "player01.xpm");
	game->player.spr.img2.ptr = ft_xpm_to_img(game, "player02.xpm");
}

static void	collec_img_init(t_game *game)
{
	game->collec.ball.ptr = ft_xpm_to_img(game, "ball.xpm");
}

static void	init_img_txt(t_game *game)
{
	game->txt.ptr = ft_xpm_to_img(game, "info_text.xpm");
	game->ending.ptr = ft_xpm_to_img(game, "ending.xpm");
}

void	init_img(t_game *game)
{
	tile_img_init(game);
	player_img_init(game);
	collec_img_init(game);
	init_img_txt(game);
}
