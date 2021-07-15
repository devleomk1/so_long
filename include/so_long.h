/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:51:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/16 05:50:20 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# include "color.h"
# include "../lib/include/libft.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC			53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

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

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_img	txt;
	t_tile	tile;
	t_clst	collec;
	t_spr	player;
	t_spr	enemy;
	int		flag;

	int		map[ROWS][COLS];
}			t_game;

void	exit_err(char *msg);

void	*ft_xpm_to_img(t_game *game, char *str);
int		ft_put_img_64(t_game *game, void *img_ptr, int x, int y);
int		ft_put_img(t_game *game, void *img_ptr, int x, int y);

#endif
