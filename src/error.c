/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:54:34 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/09 20:26:44 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_err(char *msg)
{
	ft_putstr_fd(RED "Error\n" RESET, 2);
	ft_putstr_fd(YELLOW, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RESET, 2);
	exit (EXIT_ERR);
}
