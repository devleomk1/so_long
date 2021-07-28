/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:34:08 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/28 07:39:12 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (game->flag.game_end == FALSE)
	{
		if (key_code == KEY_W)
			move_north(game, &(game->player.spr));
		else if (key_code == KEY_A)
			move_west(game, &(game->player.spr));
		else if (key_code == KEY_S)
			move_south(game, &(game->player.spr));
		else if (key_code == KEY_D)
			move_east(game, &(game->player.spr));
	}
	return (0);
}
