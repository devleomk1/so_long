/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_spin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:12:32 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/08 13:01:44 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spin_clockwise(t_spr *sprite)
{
	if (sprite->dir == DIR_NONE)
		return ;
	sprite->dir++;
	if (sprite->dir > DIR_EAST)
		sprite->dir = DIR_SOUTH;
}
