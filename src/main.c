/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:09:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/31 07:06:36 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int 	close_game(t_game *game)
{
	exit(0);
}

void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	width = game->maps.cols * TILE_SIZE;
	height = game->maps.rows * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height + 64, "so_long");
}

void	tile_img_init(t_game *game)
{
	game->tile.t0.ptr = ft_xpm_to_img(game, "tile00.xpm");
	game->tile.t1.ptr = ft_xpm_to_img(game, "tile01.xpm");
	game->tile.tl.ptr = ft_xpm_to_img(game, "ladder.xpm");
	game->tile.tb.ptr = ft_xpm_to_img(game, "num_box_16.xpm");
	game->tile.ts.ptr = ft_xpm_to_img(game, "stone.xpm");
}

void	player_img_init(t_game *game)
{
	game->player.spr.img0.ptr = ft_xpm_to_img(game, "player_fr.xpm");
	game->player.spr.img1.ptr = ft_xpm_to_img(game, "player01.xpm");
	game->player.spr.img2.ptr = ft_xpm_to_img(game, "player02.xpm");
}

void	collec_img_init(t_game *game)
{
	game->collec.ball.ptr = ft_xpm_to_img(game, "ball.xpm");
}

void	init_img_txt(t_game *game)
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

t_img	*get_player_sprimg(t_game *game)
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

static void	draw_player_walk(t_game *game, t_spr *player, t_img *sprite, int dir)
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

void	print_step_count(t_game *game)
{
	ft_putstr_fd("Step : ", 1);
	ft_putnbr_fd(game->player.spr.step, 1);
	ft_putstr_fd("\n", 1);
	game->flag.step_cnt = FALSE;
}

void	draw_step_count(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.spr.step);
	if (game->flag.step_cnt)
		print_step_count(game);
	ft_put_img64(game, game->tile.tb.ptr, 0, 0);
	mlx_string_put(game->mlx, game->win, 24, 36, 0x000000, str);
}

void	draw_collect(t_game *game)
{
	int		x;
	int		y;
	t_clst	*lst;

	x = game->player.spr.x;
	y = game->player.spr.y;
	lst = game->collec.clst;
	while (lst)
	{
		if (!lst->istouch)
		{
			if (lst->coord.x == x && lst->coord.y == y)
			{
				lst->istouch = TRUE;
				game->player.item++;
			}
			ft_put_img64(game, game->collec.ball.ptr, lst->coord.x, lst->coord.y);
		}
		lst = lst->next;
	}
}

void	event_exit(t_game *game)
{
	int	x;
	int	y;

	x = game->player.spr.x;
	y = game->player.spr.y;
	if (game->maps.coord[y][x] == 'E'
		&& game->flag.collect_all
		&& !game->flag.player_walk)
	{
		ft_putstr_fd("=====================\n", 1);
		ft_putstr_fd("THANK YOU FOR PLAYING\n", 1);
		ft_putstr_fd(" Press [ESC] to exit\n", 1);
		ft_putstr_fd("=====================\n", 1);
		ft_put_img64(game, game->ending.ptr, game->maps.cols / 2 - 1, game->maps.rows / 2);
		game->flag.game_end = TRUE;
	}
}

void	flag_checker(t_game *game)
{
	if (game->maps.cnt.c == game->player.item)
		game->flag.collect_all = TRUE;
}

int	main_loop(t_game *game)
{
	if (!game->flag.game_end)
	{
		draw_map(game);
		draw_collect(game);
		draw_player(game);
		ft_put_img(game, game->txt.ptr, 0, game->maps.rows * TILE_SIZE);
		draw_step_count(game);
		flag_checker(game);
		event_exit(game);
	}
	return (0);
}

void	init_player(t_game *game)
{
	game->player.life = LIFE_MAX;
	game->player.step = 0;
	game->player.item = 0;
	game->player.spr.step = 0;
	game->player.spr.frame = 0;
	game->player.spr.frame_max = 2;
	game->player.spr.i = 0;
}

void	init_flag(t_game *game)
{
	game->flag.collect_all = FALSE;
	game->flag.held_keys = FALSE;
	game->flag.player_walk = FALSE;
	game->flag.step_cnt = FALSE;
	game->flag.game_end = FALSE;
}

void	init_game(t_game *game)
{
	init_window(game);
	init_dir(game);
	init_img(game);
	init_player(game);
	init_flag(game);
}

void	reset_game(t_game *game)
{
	init_collec(game);
	get_compo_coord(game);
	init_player(game);
	init_flag(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_err("Usage: ./so_long [MAP_FILE.ber]\n");
	init_collec(&game);
	file_read(&game, argv[1]);
	init_game(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
