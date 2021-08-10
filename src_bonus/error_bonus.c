/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:54:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/10 17:01:02 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	exit_err(char *msg)
{
	ft_putstr_fd(RED "Error\n" RESET, 2);
	ft_putstr_fd(YELLOW, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RESET, 2);
	exit (EXIT_ERR);
}

void	debug(char *msg, int debug)
{
	if (debug == TRUE)
	{
		ft_putstr_fd("\t", 1);
		ft_putstr_fd(msg, 1);
		ft_putstr_fd(GREEN "\t\tOK\n" RESET, 1);
	}
}
