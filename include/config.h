/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:18:05 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/30 01:15:59 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*------------------------------
 * DEBUG OPTION
 *------------------------------*/
/* 1 : Debug mode ON
 * 0 : Debug mode OFF */
# define DEBUG			1

/*------------------------------
 * GAME MODE OPTION
 *------------------------------*/
/* 1 : BONUS MODE
 * 0 : MANDATORY MODE */
# define GAME_MODE		0

/*------------------------------
 * ASSET PATH
 *------------------------------*/
# define ASSET_PATH		"./asset/"

/*------------------------------
 * COMPO OPTION
 *------------------------------*/
# define COMPO_P_MAX	1
# define COMPO_C_MAX	1
# define COMPO_E_MAX	1
# define COMPO_R_MAX	0

/*------------------------------
 * PLAYER OPTION
 *------------------------------*/
/* Player Speed
 * Default	: 4
 * Min		: 1
 * Max		: 64
 * Enter only multiples of 2. */
# define PLAYER_SPEED	4
# define ENEMY_SPEED	8

#endif
