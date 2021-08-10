/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 05:47:01 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/09 15:17:59 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_collec(t_game *game)
{
	game->collec.clst = NULL;
}

void	draw_collect(t_game *game)
{
	int		x;
	int		y;
	t_clst	*lst;

	x = game->player.spr.x;
	y = game->player.spr.y;
	lst = game->collec.clst;
	while (lst)
	{
		if (!lst->istouch)
		{
			if (lst->coord.x == x && lst->coord.y == y)
			{
				lst->istouch = TRUE;
				game->player.item++;
			}
			ft_put_img64(game, game->collec.ball.ptr,
				lst->coord.x, lst->coord.y);
		}
		lst = lst->next;
	}
}
