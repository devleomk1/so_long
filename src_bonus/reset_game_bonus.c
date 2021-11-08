/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:14:05 by jisokang          #+#    #+#             */
/*   Updated: 2021/11/01 23:30:58 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

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
