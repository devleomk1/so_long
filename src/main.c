/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:09:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/18 04:05:41 by jisokang         ###   ########.fr       */
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
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (game->map[i][j] == 1)
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.t1.ptr, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 2)
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

void	init_game(t_game *game)
{
	int map[ROWS][COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 3, 1, 3, 1},
	{1, 0, 0, 1, 1, 0, 0, 1, 0, 1},
	{1, 1, 0, 0, 0, 0, 1, 1, 0, 1},
	{1, 1, 0, 3, 0, 0, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 2, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
	printf("init_game() clear\n");
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT + 64, "mlx 42");
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
void	get_map_width(t_game *game, char *line)
{
	game->maps.cols = 10;
}

void	get_map_height(t_game *game, char *line)
{
	game->maps.rows = 10;
}

void	map_read(t_game *game, char *line)
{
	int	i;
	int	j;
	int	k;

	get_map_width(game, line);
	get_map_height(game, line);
	game->maps.coord = (char **)malloc(sizeof(char *) * (game->maps.rows * game->maps.cols));
	i = 0;
	k = 0;
	while (i <= game->maps.rows)
	{
		while (j <= game->maps.cols)
		{
			printf("%c\n", line[k]);
			game->maps.coord[i][j] = line[k];
			k++;
			j++;
		}
		i++;
	}
}



t_map	*map_load_fd(t_game *game, int fd)
{
	int		gnl;
	char	*line;
	while (1)
	{
		gnl = get_next_line(fd, &line);


	}
	return ();
}

void	file_read(t_game *game, char *filename)
{
	int		fd;
	t_map	*map;
	int		gnl;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_err("File open fail\n");
	//if (check_extension())
	//{
	//	close(fd);
	//	exit_err("");
	//}
	init_map();
	map = map_load_fd(game, fd);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	map_read(game, line);
	close(fd);
	free(line);
	int i = 0;
	int j = 0;
	while (i < game->maps.height)
	{
		printf("\n");
		while (j < game->maps.width)
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

	init_game(&game);
	init_window(&game);
	init_img(&game);
	init_player(&game);
	file_read(&game, argv[1]);
	//init_collec(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
