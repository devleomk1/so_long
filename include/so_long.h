/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:51:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/15 01:13:45 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# include "color.h"
# include "../lib/include/libft.h"


# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17 //Exit program key code

# define KEY_ESC			53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define TILE_SIZE 64
# define ROWS 10
# define COLS 10

# define TRUE		1
# define FALSE		0
# define SUCCESS	1
# define FAIL		0
# define EXIT_ERR	1

# define DIR_NONE	0
# define DIR_NORTH	1
# define DIR_SOUTH	2
# define DIR_WEST	3
# define DIR_EAST	4

void	exit_err(char *msg);

#endif
