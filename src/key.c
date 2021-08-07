/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:34:08 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/07 16:28:41 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_RETURN && game->flag.game_scene == GAME_START)
		game->flag.game_scene = GAME_PLAYING;
	else if (key_code == KEY_R)
		reset_game(game);
	else if (game->flag.held_keys == FALSE)
	{
		if (key_code == KEY_W || key_code == KEY_UP)
			move_north(game, &(game->player.spr));
		else if (key_code == KEY_A || key_code == KEY_LEFT)
			move_west(game, &(game->player.spr));
		else if (key_code == KEY_S || key_code == KEY_DOWN)
			move_south(game, &(game->player.spr));
		else if (key_code == KEY_D || key_code == KEY_RIGHT)
			move_east(game, &(game->player.spr));
	}
	return (0);
}
