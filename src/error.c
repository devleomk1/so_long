/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:54:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/12 01:13:46 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_err(char *msg)
{
	ft_putstr_fd(RED "Error\n" RESET, 2);
	ft_putstr_fd(msg, 2);
	exit (EXIT_ERR);
}
