/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:09:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/06 16:32:50 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	exit(0);
}

void	frame_cunt(t_game *game)
{
	game->fps++;
	if (game->fps >= 600)
		game->fps = 0;
}

int	main_loop(t_game *game)
{
	if (game->flag.game_over)
		draw_gameover(game);
	else if (game->flag.game_end)
		draw_ending(game);
	else
	{
		draw_map(game);
		draw_collect(game);
		flag_checker(game);
		enemy_script(game);
		draw_sprites(game);
		draw_step_count(game);
		event_exit(game);
	}
	frame_cunt(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_err("Usage: ./so_long [MAP_FILE.ber]\n");
	init_collec(&game);
	file_read(&game, argv[1]);
	init_game(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
