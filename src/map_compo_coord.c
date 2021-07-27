/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compo_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:14:54 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/27 22:58:21 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_compo_cnt(t_game *game)
{
	game->maps.cnt.p = 0;
	game->maps.cnt.e = 0;
	game->maps.cnt.c = 0;
}

static void	_compo_coord(t_game *game, int i, int j)
{
	if (game->maps.coord[i][j] == 'P')
	{
		game->player.spr.x = j;
		game->player.spr.y = i;
		game->maps.cnt.p++;
	}
	else if (game->maps.coord[i][j] == 'C')
	{
		game->maps.cnt.c++;
		clst_add_back(&(game->collec.clst), clst_new(game, j, i));
	}
	else if (game->maps.coord[i][j] == 'E')
		game->maps.cnt.e++;
}

int	check_compo_cnt(t_game *game)
{
	if (game->maps.cnt.p != 1)
		return (FALSE);
	if (game->maps.cnt.e != 1)
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
