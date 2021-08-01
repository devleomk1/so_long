/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 07:16:05 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/31 07:16:23 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_step_count(t_game *game)
{
	ft_putstr_fd("Step : ", 1);
	ft_putnbr_fd(game->player.spr.step, 1);
	ft_putstr_fd("\n", 1);
	game->flag.step_cnt = FALSE;
}

void	draw_step_count(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.spr.step);
	if (game->flag.step_cnt)
		print_step_count(game);
	ft_put_img64(game, game->tile.tb.ptr, 0, 0);
	mlx_string_put(game->mlx, game->win, 24, 36, 0x000000, str);
}
