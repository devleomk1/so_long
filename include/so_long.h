/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:51:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/24 01:00:32 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# include "color.h"
# include "key.h"
# include "../mlx/mlx.h"
# include "../lib/include/libft.h"
# include "../lib/include/get_next_line.h"

# define TILE_SIZE 64
# define ROWS 10
# define COLS 10

# define TRUE		1
# define FALSE		0
# define SUCCESS	1
# define FAIL		0
# define EXIT_ERR	1

# define DIR_NONE	0
# define DIR_NORTH	1
# define DIR_SOUTH	2
# define DIR_WEST	3
# define DIR_EAST	4

# define MAP_EXT	".ber"

#define WIDTH COLS * TILE_SIZE
#define HEIGHT ROWS * TILE_SIZE

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_img
{
	void	*ptr;
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
	int		step;
	int		invis;
	int		flag;
}			t_spr;

typedef struct s_clst
{
	t_img			ball;
	int				x;
	int				y;
	int				istouch;
	struct s_clst	*next;
}					t_clst;

typedef struct	s_map
{
	int		rows;
	int		cols;
	char	**coord;
}			t_map;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img64;
	t_img	txt;
	t_tile	tile;
	t_clst	collec;
	t_spr	player;
	t_spr	enemy;
	t_coord	dir2coord[5];
	int		flag;
	t_map	maps;
	int		map[ROWS][COLS];
}			t_game;

void	exit_err(char *msg);

void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img64(t_game *game, void *img_ptr, int x, int y);
void	ft_put_img(t_game *game, void *img_ptr, int x, int y);

void	init_dir(t_game *game);
void	dir_to_coord(int dir, int *x, int *y);
int		is_collision(t_game *game, t_spr *sprite, int dir);
void	move_north(t_game *game, t_spr *sprite);
void	move_south(t_game *game, t_spr *sprite);
void	move_west(t_game *game, t_spr *sprite);
void	move_east(t_game *game, t_spr *sprite);

int		check_ext(char *str, char *ext);

#endif
