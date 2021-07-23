/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:09:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/24 05:26:37 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../include/so_long.h"

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
			//if (game->map[i][j] == 3)
			//	//game->collect.cnt++;
			j++;
		}
		i++;
	}
}

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_W)
		move_north(game, &(game->player));
	else if (key_code == KEY_A)
		move_west(game, &(game->player));
	else if (key_code == KEY_S)
		move_south(game, &(game->player));
	else if (key_code == KEY_D)
		move_east(game, &(game->player));
	return (0);
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
	printf("init_img() clear\n");
}

void	draw_player(t_game *game)
{
	if (game->flag == 1)
		ft_put_img64(game, game->player.img1.ptr,
			game->player.x, game->player.y);
	else if (game->flag == 2)
		ft_put_img64(game, game->player.img2.ptr,
			game->player.x, game->player.y);
	else
		ft_put_img64(game, game->player.img0.ptr,
			game->player.x, game->player.y);
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
/**
 * 			col 0	col 1
 * row 0	[  ]	[  ]
 * row 1	[  ]	[  ]
 */

void	count_max_rows_cols(t_game *game, int fd)
{
	int		read_size;
	int		tmp_cols;
	char	c;

	game->maps.rows = 0;
	game->maps.cols = 0;
	tmp_cols = 0;
	while((read_size = read(fd, &c, 1)) > 0)
	{
		if (game->maps.cols < tmp_cols)
			game->maps.cols = tmp_cols;
		if (c == '\n')
		{
			game->maps.rows++;
			tmp_cols = 0;
		}
		else
			tmp_cols++;
	}
	printf("MAX_cols : %d\nMAX_rows : %d\n", game->maps.cols, game->maps.rows);
}

void	map_malloc(t_game *game, int fd)
{
	int	i;

	count_max_rows_cols(game, fd);
	game->maps.coord = (char **)malloc(sizeof(char *) * (game->maps.rows));
	i = 0;
	while (i < game->maps.rows)
	{
		game->maps.coord[i] = (char *)malloc(sizeof(char) * (game->maps.cols));
		i++;
	}
	ft_memset(&(game->maps.coord[0][0]), ' ', (game->maps.cols * game->maps.rows));
}

int		open_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit_err("File open fail\n");
	return (fd);
}

void	map_load(t_game *game, char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open_file(filename);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			game->maps.coord[i][j] = line[j];
			printf("[%c]", game->maps.coord[i][j]);
			j++;
		}
		printf("\n");
		i++;
		free(line);
	}
	free(line);
	close(fd);
}

void	file_read(t_game *game, char *filename)
{
	int		fd;
	int		gnl;

	check_ext(filename, MAP_EXT);
	fd = open_file(filename);
	map_malloc(game, fd);
	close(fd);
	map_load(game, filename);
	//아니 어떻게 몇줄인지 알지? 진짜 2번 읽어야 하나?

	int i = 0;
	int j = 0;
	while (i < game->maps.rows)
	{
		printf("\n");
		while (j < game->maps.cols)
		{
			printf("[%c]", game->maps.coord[i][j]);
			if (game->maps.coord[i][j] == 'P')
			{
				game->player.x = i;
				game->player.y = j;
				printf("Read player coord OK\n");
				printf("(%d, %d)\n", game->player.x, game->player.x);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	main_loop(t_game *game)
{
	draw_map(game);
	draw_player(game);
	//draw_collect(game);
	ft_put_img(game, game->txt.ptr, 0, HEIGHT);
	draw_step_count(game);
	return (0);
}

void	init_player(t_game *game)
{
	game->player.x = 1;
	game->player.y = 1;
	game->player.step = 0;
	game->player.flag = FALSE;
	game->flag = 0;
	printf("init_player() clear\n");
}

void	init_collec(t_game *game)
{
	//init_collec_lst();
}

int	main(int argc, char **argv)
{
	t_game	game;

	file_read(&game, argv[1]);
	//init_game(&game);
	init_window(&game);
	init_img(&game);
	init_player(&game);
	init_dir(&game);
	//init_collec(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
