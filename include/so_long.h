/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:51:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/05 22:08:49 by jisokang         ###   ########.fr       */
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

# define TILE_SIZE		64

# define TRUE			1
# define FALSE			0
# define SUCCESS		1
# define FAIL			0

# define DIR_NONE		0
# define DIR_NORTH		1
# define DIR_SOUTH		2
# define DIR_WEST		3
# define DIR_EAST		4

/* Player */
# define LIFE_MAX		1
# define P_MAX_FRAME	3	//0, 1, 2, 3

/**
 * Player Speed
 * Default	: 4
 * Min		: 1
 * Max		: 64
 * Enter only multiples of 2.
 */
# define PLAYER_SPEED	4
# define ENEMY_SPEED	8

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
	t_img	nl;
}			t_tile;

typedef struct s_spr
{
	t_img	imgx[5][3];
	int		frame;
	int		frame_max;
	int		step;
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		i;
	int		dir;
	int		move;
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
	int		r;
}			t_compo;


typedef struct	s_map
{
	int		rows;
	int		cols;
	char	**coord;
	char	*file;
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
	int		held_keys;
	int		player_walk;
	int		enemy_walk;
	int		step_cnt;
	int		game_opening;
	int		game_over;
	int		game_end;
}			t_flags;


typedef struct	s_game
{
	void		*mlx;
	void		*win;
	int			fps;
	t_img		img64;
	t_spr		pika;
	t_img		gameover;
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
void	init_player(t_game *game);
void	init_flag(t_game *game);
void	init_game(t_game *game);
int		reset_game(t_game *game);

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

void	draw_map(t_game *game);
void	init_img(t_game *game);
void	draw_player(t_game *game);
void	draw_enemy(t_game *game);
void	draw_step_count(t_game *game);

int		_move_dir(t_game *game, t_spr *sprite, int dir);
void	spin_clockwise(t_game *game, t_spr *sprite);

#endif
