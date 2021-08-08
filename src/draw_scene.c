/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:05:07 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/08 11:57:20 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*get_end_anim_spr(t_game *game)
{
	int		*i;

	i = &(game->pika.i);
	if (*i >= 60)
		*i = 0;
	if (20 <= *i && *i < 40)
		return (&(game->pika.imgx[0][1]));
	else
		return (&(game->pika.imgx[0][0]));
}

void	_draw_ending_pika(t_game *game)
{
	int		i;
	int		j;
	t_img	*spr;

	spr = get_end_anim_spr(game);
	i = 0;
	while (i < game->maps.cols)
	{
		j = 0;
		while (j < game->maps.rows)
		{
			ft_put_img64(game, spr->ptr, i, j);
			j++;
		}
		i++;
	}
	game->pika.i++;
}

void	draw_scene_event(t_game *game)
{
	int		x;
	int		y;

	x = game->maps.cols / 2 - 2;
	y = game->maps.rows / 2 - 2;
	mlx_clear_window(game->mlx, game->win);
	if (game->flag.game_scene == GAME_START)
		ft_put_img64(game, game->opening.ptr, x, y);
	else if (game->flag.game_scene == GAME_OVER)
		ft_put_img64(game, game->gameover.ptr, x, y);
	else if (game->flag.game_scene == GAME_ENDING)
	{
		_draw_ending_pika(game);
		ft_put_img64(game, game->ending.ptr, x, y);
	}
	else
		exit_err("GAME SCENE ERROR\n");
}
