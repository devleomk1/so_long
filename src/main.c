/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:09:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/15 14:39:11 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../mlx/mlx.h"
#include "../include/so_long.h"

#define WIDTH COLS * TILE_SIZE
#define HEIGHT ROWS * TILE_SIZE

typedef struct s_img
{
	void	*img;
	int		*data;
	int		h;
	int		w;

	int		size_l;
	int		bpp;
	int		endian;
}			t_img;

typedef struct s_tile
{
	t_img	t0;
	t_img	t1;
	t_img	tl;
	t_img	tb;
}			t_tile;

typedef struct s_spr
{
	t_img	img0;
	t_img	img1;
	t_img	img2;
	int		x;
	int		y;
	int		flag;
	int		step;
	int		cnt;
}			t_spr;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_img	txt;
	t_tile	tile;
	t_spr	player;
	t_spr	collect;
	t_spr	enemy;
	int		flag;

	int		map[ROWS][COLS];
}			t_game;

void draw_step_count(t_game *game);

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
					game->tile.t1.img, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 2)
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.tl.img, j * TILE_SIZE, i * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.t0.img, j * TILE_SIZE, i * TILE_SIZE);
			if (game->map[i][j] == 3)
				game->collect.cnt++;
			j++;
		}
		i++;
	}
}

void	dir_to_coord(int dir, int *x, int *y)
{
	if (dir == DIR_NORTH)
	{
		*x = 0;
		*y = -1;
	}
	else if (dir == DIR_SOUTH)
	{
		*x = 0;
		*y = 1;
	}
	else if (dir == DIR_WEST)
	{
		*x = -1;
		*y = 0;
	}
	else if (dir == DIR_EAST)
	{
		*x = 1;
		*y = 0;
	}
}

int	is_collision(t_game *game, t_spr *sprite, int dir)
{
	int	x;
	int	y;

	dir_to_coord(dir, &x, &y);
	if (game->map[sprite->y + y][sprite->x + x] == 1)
		return (TRUE);
	return (FALSE);
}

int	_move_dir(t_game *game, t_spr *sprite, int dir)
{
	int	x;
	int	y;

	if (!is_collision(game, sprite, dir))
	{
		dir_to_coord(dir, &x, &y);
		sprite->x += x;
		sprite->y += y;
		sprite->step++;
		printf("step : %d\n", sprite->step);
	}
	game->flag++;
	if (game->flag > 2)
		game->flag = 0;
	return (1);
}

void	move_north(t_game *game, t_spr *sprite)
{
	_move_dir(game, sprite, DIR_NORTH);
}

void	move_south(t_game *game, t_spr *sprite)
{
	_move_dir(game, sprite, DIR_SOUTH);
}

void	move_west(t_game *game, t_spr *sprite)
{
	_move_dir(game, sprite, DIR_WEST);
}

void	move_east(t_game *game, t_spr *sprite)
{
	_move_dir(game, sprite, DIR_EAST);
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

void	game_init(t_game *game)
{
	game->player.x = 1;
	game->player.y = 1;
	game->player.step = 0;
	game->flag = 0;

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
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT + 64, "mlx 42");
}

void	tile_img_init(t_game *game)
{
	game->tile.t0.img = mlx_xpm_file_to_image(game->mlx,
			"tile00.xpm", &(game->img.w), &(game->img.h));
	game->tile.t1.img = mlx_xpm_file_to_image(game->mlx,
			"tile01.xpm", &(game->img.w), &(game->img.h));
	game->tile.tl.img = mlx_xpm_file_to_image(game->mlx,
			"tile_ladder.xpm", &(game->img.w), &(game->img.h));
	game->tile.tb.img = mlx_xpm_file_to_image(game->mlx,
			"num_box_16.xpm", &(game->img.w), &(game->img.h));
}

void	player_img_init(t_game *game)
{
	game->player.img0.img = mlx_xpm_file_to_image(game->mlx,
			"player.xpm", &(game->img.w), &(game->img.h));
	game->player.img1.img = mlx_xpm_file_to_image(game->mlx,
			"player01.xpm", &(game->img.w), &(game->img.h));
	game->player.img2.img = mlx_xpm_file_to_image(game->mlx,
			"player02.xpm", &(game->img.w), &(game->img.h));
}

void	img_init(t_game *game)
{
	tile_img_init(game);
	player_img_init(game);
	game->txt.img = mlx_xpm_file_to_image(game->mlx,
			"info_text.xpm", &(game->txt.w), &(game->txt.h));
}

void	draw_player(t_game *game)
{
	if (game->flag == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->player.img1.img,
			game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	else if (game->flag == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->player.img2.img,
			game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->player.img0.img,
			game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
}

void	draw_step_count(t_game *game)
{
	char *str;
	str = ft_itoa(game->player.step);
	mlx_put_image_to_window(game->mlx, game->win, game->tile.tb.img, 0, 0);
	mlx_string_put(game->mlx, game->win, 26, 36, 0x000000, str);
}

void	draw_collect(t_game *game)
{

}

int		main_loop(t_game *game)
{
	draw_map(game);
	draw_player(game);
	draw_collect(game);
	mlx_put_image_to_window(game->mlx, game->win, game->txt.img, 0, HEIGHT);
	draw_step_count(game);
	return (0);
}

int	main(void)
{
	t_game	game;

	game_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
