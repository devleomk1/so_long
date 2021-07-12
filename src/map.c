/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:37:55 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/12 01:40:47 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ext(char *str, char *ext)
{
	int	i;
	int	j;

	i = 0;
	if (ext[0] != '.')
		exit_err("Invalid function parameter.\n");
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

int	main(int argc, char **argv)
{
	if (check_ext(argv[1], ".ber"))
	{
		printf("Ext Check" GREEN" OK\n"RESET);
	}
	return (0);
}
