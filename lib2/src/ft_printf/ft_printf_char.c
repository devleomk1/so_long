/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:42:42 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 16:40:26 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print_char(t_info *info, va_list ap)
{
	int		printed;
	char	c;

	printed = 0;
	if (info->minus == DISABLE)
	{
		while (--(info->width) > 0)
			printed += write(1, " ", 1);
	}
	c = (unsigned char)va_arg(ap, int);
	printed += write(1, &c, 1);
	while (--(info->width) > 0)
		printed += write(1, " ", 1);
	return (printed);
}

int	ft_print_percent(t_info *info)
{
	int		printed;

	printed = 0;
	if (info->minus == DISABLE && info->zero == DISABLE)
	{
		while (--(info->width) > 0)
			printed += write(1, " ", 1);
	}
	if (info->minus == DISABLE && info->zero == ENABLE)
	{
		while (--(info->width) > 0)
			printed += write(1, "0", 1);
	}
	printed += write(1, "%", 1);
	while (--(info->width) > 0)
		printed += write(1, " ", 1);
	return (printed);
}
