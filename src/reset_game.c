/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:14:05 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/08 10:32:24 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	reset_game(t_game *game)
{
	ft_putstr_fd("RESET\n", 1);
	game->flag.game_scene = GAME_PLAYING;
	init_collec(game);
	get_compo_coord(game);
	init_player(game);
	init_enemy(game);
	init_flag(game);
	return (0);
}
