/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:51:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/11 00:30:33 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <string.h>

# include "color_bonus.h"
# include "key_bonus.h"
# include "error_bonus.h"
# include "map_bonus.h"
# include "config_bonus.h"
# include "../mlx/mlx.h"
# include "../lib/include/libft.h"
# include "../lib/include/get_next_line.h"

/* Game mode */
# define MANDATORY		0
# define BONUS			1

# define TRUE			1
# define FALSE			0
//서큘러 비트 시프트!
# define DIR_NONE		0
# define DIR_SOUTH		1
# define DIR_WEST		2
# define DIR_NORTH		3
# define DIR_EAST		4

/* Game Scene Status */
# define GAME_START		0
# define GAME_PLAYING	1
# define GAME_OVER		2
# define GAME_ENDING	3

/* Player */
# define P_MAX_FRAME	3

typedef struct s_map	t_map;

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_clst
{
	t_coord			coord;
	int				istouch;
	struct s_clst	*next;
}					t_clst;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		h;
	int		w;
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

typedef struct s_coll
{
	t_img	ball;
	t_clst	*clst;
}			t_coll;

typedef struct s_player
{
	t_spr	spr;
	int		life;
	int		step;
	int		item;
}			t_player;

typedef struct s_flags
{
	int		collect_all;
	int		held_keys;
	int		player_walk;
	int		enemy_walk;
	int		step_cnt;
	int		game_scene;
}			t_flags;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			fps;
	t_img		img64;
	t_img		opening;
	t_img		gameover;
	t_img		ending;
	t_tile		tile;
	t_coll		collec;
	t_player	player;
	t_spr		enemy;
	t_spr		pika;
	t_coord		dir2coord[5];
	t_map		maps;
	t_flags		flag;
}				t_game;

void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img64(t_game *game, void *img_ptr, int x, int y);
void	ft_put_img(t_game *game, void *img_ptr, int x, int y);

void	init_collec(t_game *game);
void	draw_collect(t_game *game);

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

t_clst	*clst_new(int x, int y);
t_clst	*clst_last(t_clst *lst);
void	clst_add_back(t_clst **lst, t_clst *new);
void	clst_clear(t_clst *head);

void	draw_map(t_game *game);
void	init_img(t_game *game);
void	draw_player(t_game *game);
void	draw_enemy(t_game *game);
void	draw_step_count(t_game *game);
void	draw_scene_event(t_game *game);

void	event_checker(t_game *game);
void	enemy_script(t_game *game);
void	draw_sprites(t_game *game);
void	init_enemy(t_game *game);

void	move_dir(t_game *game, t_spr *sprite, int dir);
void	spin_clockwise(t_spr *sprite);

void	init_window(t_game *game);
int		close_game(t_game *game);

#endif
