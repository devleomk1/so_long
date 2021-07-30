/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:17:43 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/29 17:12:17 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * check map file components
 * 0 : an empty space.
 * 1 : a wall.
 * C : a collectible.
 * E : map exit.
 * P : the player’s starting position.
 */
int	check_map_compo(char c)
{
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P' || c == ' '
		|| c == 'S')
		return (TRUE);
	return (FALSE);
}

int	is_map_rectangle(t_game *game, int len2)
{
	int	len1;

	len1 = game->maps.cols;
	if (len1 != len2)
		return (FALSE);
	return (TRUE);
}

int	is_map_walled(t_map maps)
{
	int	max_col;
	int	max_row;
	int	i;

	i = 0;
	max_col = maps.cols - 1;
	max_row = maps.rows - 1;
	while (i < maps.rows)
	{
		if (maps.coord[i][0] != '1' || maps.coord[i][max_col] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < maps.cols)
	{
		if (maps.coord[0][i] != '1' || maps.coord[max_row][i] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
