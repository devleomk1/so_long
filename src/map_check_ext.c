/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:18:38 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/07 18:27:30 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ext(char *str, char *ext)
{
	int	i;
	int	j;

	i = 0;
	if (ext[0] != '.')
		exit_err("Invalid function parameter. ext[0] must be 'dot' charter\n");
	if (str[0] == '.' && str[1] == '.')
		i += 2;
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
