/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 07:01:55 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/02 18:07:55 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_draw_map(t_game *game, int i, int j)
{
	if (game->maps.coord[i][j] == '1')
		ft_put_img64(game, game->tile.t1.ptr, j, i);
	else if (game->maps.coord[i][j] == 'E')
	{
		if (game->flag.collect_all)
			ft_put_img64(game, game->tile.tl.ptr, j, i);
		else
		{
			ft_put_img64(game, game->tile.t0.ptr, j, i);
			ft_put_img64(game, game->tile.ts.ptr, j, i);
		}
	}
	else
		ft_put_img64(game, game->tile.t0.ptr, j, i);
}

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
			_draw_map(game, i, j);
			j++;
		}
		i++;
	}
}
