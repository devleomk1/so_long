/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:18:05 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/10 16:34:11 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

/*------------------------------
 * DEBUG OPTION
 *------------------------------*/
/* 1 : Debug mode ON
 * 0 : Debug mode OFF */
# define DEBUG			0

/*------------------------------
 * GAME MODE OPTION
 *------------------------------*/
/* 1 : BONUS MODE
 * 0 : MANDATORY MODE */
# define GAME_MODE		1

/*------------------------------
 * ASSET PATH
 *------------------------------*/
# define ASSET_PATH		"./asset/"

/*------------------------------
 * COMPO OPTION
 *------------------------------*/
# define COMPO_P_MAX	1
# define COMPO_E_MAX	1
# define COMPO_R_MAX	1

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
