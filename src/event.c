/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:12:02 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/07 16:35:35 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	event_exit(t_game *game)
{
	int	x;
	int	y;

	x = game->player.spr.x;
	y = game->player.spr.y;
	if (game->maps.coord[y][x] == 'E'
		&& game->flag.collect_all
		&& !game->flag.player_walk)
	{
		ft_putstr_fd("=====================\n", 1);
		ft_putstr_fd("THANK YOU FOR PLAYING\n", 1);
		ft_putstr_fd(" Press [ESC] to exit\n", 1);
		ft_putstr_fd(" Press  [R] to retry\n", 1);
		ft_putstr_fd("=====================\n", 1);
		//game->flag.game_end = TRUE;
		game->flag.game_scene = GAME_ENDING;
	}
}

void	flag_checker(t_game *game)
{
	if (game->maps.cnt.c == game->player.item)
		game->flag.collect_all = TRUE;
	if (game->player.spr.x == game->enemy.x
		&& game->player.spr.y == game->enemy.y
		&& !game->flag.enemy_walk)
	{
		ft_putstr_fd("=====================\n", 1);
		ft_putstr_fd("      YOU DIED\n", 1);
		ft_putstr_fd(" Press [ESC] to exit\n", 1);
		ft_putstr_fd(" Press  [R] to retry\n", 1);
		ft_putstr_fd("=====================\n", 1);
		//game->flag.game_over = TRUE;
		game->flag.game_scene = GAME_ENDING;
	}
}
