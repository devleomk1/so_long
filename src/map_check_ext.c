/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:18:38 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/09 15:50:06 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ext(char *str, char *ext)
{
	int	i;
	int	j;

	if (ext[0] != '.')
		exit_err("Invalid function parameter. ext[0] must be 'dot' charter\n");
	i = ft_strlen(str) - ft_strlen(ext);
	if (i <= 0 || str[i] != '.')
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
