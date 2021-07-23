/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:37:55 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/24 01:09:17 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ext(char *str, char *ext)
{
	int	i;
	int	j;

	i = 0;
	if (ext[0] != '.')
		exit_err("Invalid function parameter. ext[0] must be dot charter\n");
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (!str[i])
		exit_err("Wrong extension or file path.\n");
	j = 0;
	while (str[i + j] != '\0' && ext[j] != '\0')
	{
		if (str[i + j] == ext[j])
			j++;
		else
			break ;
	}
	if (!(str[i + j] == '\0' && ext[j] == '\0'))
		exit_err("Wrong extension or file path.\n");
	return (TRUE);
}

/**
 * check map components
 * 0 : an empty space.
 * 1 : a wall.
 * C : a collectible.
 * E : map exit.
 * P : the player’s starting position.
 */
int	check_map_compo(char c)
{
	//add ' ' for cub3d
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P' || c == ' ' || c == '\n')
		return (TRUE);
	return (FALSE);
}

int	check_map_rectangle(void)
{

}

int	check_map(char **argv)
{

}

int	main(int argc, char **argv)
{
	if (check_ext(argv[1], ".ber"))
	{
		printf("Ext Check" GREEN" OK\n"RESET);
	}
	return (0);
}
