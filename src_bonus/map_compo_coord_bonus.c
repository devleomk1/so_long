/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compo_coord_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:14:54 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/30 01:17:31 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	init_compo_cnt(t_game *game)
{
	game->maps.cnt.p = 0;
	game->maps.cnt.e = 0;
	game->maps.cnt.c = 0;
	game->maps.cnt.r = 0;
}

static void	_compo_coord(t_game *game, int i, int j)
{
	if (game->maps.coord[i][j] == 'P')
	{
		game->player.spr.x = j;
		game->player.spr.x0 = j;
		game->player.spr.y = i;
		game->player.spr.y0 = i;
		game->maps.cnt.p++;
	}
	else if (game->maps.coord[i][j] == 'C')
	{
		game->maps.cnt.c++;
		clst_add_back(&(game->collec.clst), clst_new(j, i));
	}
	else if (game->maps.coord[i][j] == 'R')
	{
		game->enemy.x = j;
		game->enemy.x0 = j;
		game->enemy.y = i;
		game->enemy.y0 = i;
		game->maps.cnt.r++;
	}
	else if (game->maps.coord[i][j] == 'E')
		game->maps.cnt.e++;
}

int	check_compo_cnt(t_game *game)
{
	if (!(0 < game->maps.cnt.p && game->maps.cnt.p <= COMPO_P_MAX))
		return (FALSE);
	if (!(0 < game->maps.cnt.p && game->maps.cnt.p <= COMPO_C_MAX))
		return (FALSE);
	if (!(0 < game->maps.cnt.e && game->maps.cnt.e <= COMPO_E_MAX))
		return (FALSE);
	if (!(0 <= game->maps.cnt.r && game->maps.cnt.r <= COMPO_R_MAX))
		return (FALSE);
	return (TRUE);
}

void	get_compo_coord(t_game *game)
{
	int	i;
	int	j;

	init_compo_cnt(game);
	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			_compo_coord(game, i, j);
			j++;
		}
		i++;
	}
	if (check_compo_cnt(game) == FALSE)
		exit_err("Invalid number of components found.\n");
}
