/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:51:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/28 16:01:39 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "color.h"
# include "key.h"
# include "error.h"
# include "../mlx/mlx.h"
# include "../lib/include/libft.h"
# include "../lib/include/get_next_line.h"

# define MAP_EXT	".ber"

# define TILE_SIZE 64

# define TRUE		1
# define FALSE		0
# define SUCCESS	1
# define FAIL		0

# define DIR_NONE	0
# define DIR_NORTH	1
# define DIR_SOUTH	2
# define DIR_WEST	3
# define DIR_EAST	4

# define LIFE_MAX	1

# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

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
	t_img	ts;
}			t_tile;

typedef struct s_spr
{
	t_img	img0;
	t_img	img1;
	t_img	img2;
	int		frame;
	int		frame_max;
	int		step;
	int		x;
	int		y;
	int		x2;
	int		y2;
	int		i;
}			t_spr;

typedef struct s_clst
{
	t_coord			coord;
	int				istouch;
	struct s_clst	*next;
}					t_clst;

typedef struct s_coll
{
	t_img	ball;
	t_clst	*clst;
}			t_coll;

typedef struct s_compo
{
	int		p;
	int		e;
	int		c;
}			t_compo;


typedef struct	s_map
{
	int		rows;
	int		cols;
	char	**coord;
	t_compo	cnt;
}			t_map;

typedef struct	s_player
{
	t_spr	spr;
	int		life;
	int		step;
	int		item;
}			t_player;

typedef struct	s_flags
{
	int		collect_all;
	int		player_walk;
	int		game_end;
}			t_flags;


typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img64;
	t_img		txt;
	t_img		ending;
	t_tile		tile;
	t_coll		collec;
	t_player	player;
	t_spr		enemy;
	t_coord		dir2coord[5];
	t_map		maps;
	t_flags		flag;
}				t_game;

void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img64(t_game *game, void *img_ptr, int x, int y);
void	ft_put_img(t_game *game, void *img_ptr, int x, int y);

void	init_collec(t_game *game);

void	init_dir(t_game *game);
void	dir_to_coord(int dir, int *x, int *y);
int		is_collision(t_game *game, t_spr *sprite, int dir);
void	move_north(t_game *game, t_spr *sprite);
void	move_south(t_game *game, t_spr *sprite);
void	move_west(t_game *game, t_spr *sprite);
void	move_east(t_game *game, t_spr *sprite);

int		check_ext(char *str, char *ext);
int		check_map_compo(char c);
int		is_map_rectangle(t_game *game, int len2);
int		is_map_walled(t_map maps);
void	count_max_rows_cols(t_game *game, int fd);
void	map_malloc(t_game *game, int fd);
int		open_file(char *filename);
void	map_load(t_game *game, char *filename);
void	get_compo_coord(t_game *game);
void	file_read(t_game *game, char *filename);

int		deal_key(int key_code, t_game *game);

t_clst	*clst_new(t_game *game, int x, int y);
t_clst	*clst_last(t_clst *lst);
void	clst_add_back(t_clst **lst, t_clst *new);
void	clst_clear(t_clst *head);

#endif
