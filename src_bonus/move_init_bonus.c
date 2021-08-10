/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:54:23 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/10 17:01:02 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	init_dir(t_game *game)
{
	game->dir2coord[DIR_NONE] = (t_coord){0, 0};
	game->dir2coord[DIR_NORTH] = (t_coord){0, -1};
	game->dir2coord[DIR_SOUTH] = (t_coord){0, 1};
	game->dir2coord[DIR_WEST] = (t_coord){-1, 0};
	game->dir2coord[DIR_EAST] = (t_coord){1, 0};
}
