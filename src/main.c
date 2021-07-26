/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:09:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/27 04:34:29 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "so_long.h"

time_t start;

void	draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			if (game->maps.coord[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.t1.ptr, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->maps.coord[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.tl.ptr, j * TILE_SIZE, i * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.t0.ptr, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

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
	game->win = mlx_new_window(game->mlx, width, height + 64, "mlx 42");
	printf("init_window() clear\n");
}

void	tile_img_init(t_game *game)
{
	game->tile.t0.ptr = ft_xpm_to_img(game, "tile00.xpm");
	game->tile.t1.ptr = ft_xpm_to_img(game, "tile01.xpm");
	game->tile.tl.ptr = ft_xpm_to_img(game, "tile_ladder.xpm");
	game->tile.tb.ptr = ft_xpm_to_img(game, "num_box_16.xpm");
}

void	player_img_init(t_game *game)
{
	game->player.img0.ptr = ft_xpm_to_img(game, "player.xpm");
	game->player.img1.ptr = ft_xpm_to_img(game, "player01.xpm");
	game->player.img2.ptr = ft_xpm_to_img(game, "player02.xpm");
}

void	init_img(t_game *game)
{
	tile_img_init(game);
	player_img_init(game);
	game->txt.ptr = ft_xpm_to_img(game, "info_text.xpm");
}

void	draw_player(t_game *game)
{
	if (game->flag == 1)
		ft_put_img(game, game->player.img1.ptr,
			game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	else if (game->flag == 2)
		ft_put_img(game, game->player.img2.ptr,
			game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	else
		ft_put_img(game, game->player.img0.ptr,
			game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
}

void	draw_step_count(t_game *game)
{
	char *str;

	str = ft_itoa(game->player.step);
	mlx_put_image_to_window(game->mlx, game->win, game->tile.tb.ptr, 0, 0);
	mlx_string_put(game->mlx, game->win, 24, 36, 0x000000, str);
}

void	draw_collect(t_game *game)
{

}


int	main_loop(t_game *game)
{
	/************* FPS Frame *************/
	static int fps = 0;
	time_t end;

	fps++;
	time(&end);
	if (game->flag > 2)
		game->flag = 0;
	if (!(fps % 30))
	{
		game->flag++;
	}
	if ((float)(end - start) >= 1.0)
	{
		printf("fps : %d\n", fps);
		fps = 0;
		time(&start);
	}
	/************* ********* *************/
	draw_map(game);
	draw_player(game);
	//draw_collect(game);
	ft_put_img(game, game->txt.ptr, 0, game->maps.rows * TILE_SIZE);
	draw_step_count(game);
	return (0);
}

void	init_player(t_game *game)
{
	game->player.step = 0;
	game->player.flag = FALSE;
	game->flag = 0;
}

void	init_collec(t_game *game)
{
	//init_collec_lst();
}

void	init_game(t_game *game)
{
	init_window(game);
	init_img(game);
	init_player(game);
	init_dir(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_err("Usage: ./so_long [MAP_FILE.ber]\n");
	file_read(&game, argv[1]);
	init_game(&game);
	//init_collec(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
