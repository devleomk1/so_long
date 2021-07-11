/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:37:55 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/11 20:49:32 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_ext(char *str, char *ext)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (!str[i])
	{
		printf("ERROR\n");
		exit(1);
	}
	while (str[i + j] != '\0' && ext[j] != '\0')
	{
		if (str[i+j] == ext[j])
			j++;
		break;
	}
	if (str[i + j] == '\0' && ext[j] == '\0')
		return (1);
	printf("ERROR\n");
	exit(1);
}
