/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_spin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:12:32 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/09 15:17:59 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	spin_clockwise(t_spr *sprite)
{
	if (sprite->dir == DIR_NONE)
		return ;
	sprite->dir++;
	if (sprite->dir > DIR_EAST)
		sprite->dir = DIR_SOUTH;
}
