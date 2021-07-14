/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:51:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/14 16:37:19 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# include "color.h"
# include "../lib/include/libft.h"

# define TRUE		1
# define FALSE		0
# define SUCCESS	1
# define FAIL		0
# define EXIT_ERR	1

# define DIR_NORTH	1
# define DIR_SOUTH	2
# define DIR_WEST	3
# define DIR_EAST	4

void	exit_err(char *msg);

#endif
