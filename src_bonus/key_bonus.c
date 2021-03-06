/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:34:08 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/10 17:01:02 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_RETURN && game->flag.game_scene == GAME_START)
		game->flag.game_scene = GAME_PLAYING;
	else if (key_code == KEY_R && game->flag.game_scene != GAME_START)
		reset_game(game);
	else if (!game->flag.held_keys && game->flag.game_scene == GAME_PLAYING)
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
