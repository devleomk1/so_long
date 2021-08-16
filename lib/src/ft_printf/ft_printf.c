/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:37:49 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/23 20:25:40 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	init_struct(t_info *info)
{
	info->minus = DISABLE;
	info->zero = DISABLE;
	info->dot_only = DISABLE;
	info->locass = DISABLE;
	info->address = DISABLE;
	info->width = -1;
	info->precision = -1;
	info->num_base = 10;
	info->num_sign = 0;
}

int		ft_parse_symbols(const char *format, va_list ap)
{
	t_info		info;
	int			printed;

	printed = 0;
	while (*format != 0)
	{
		init_struct(&info);
		if (*format == '%')
		{
			format++;
			ft_parse_flag(&format, &info);
			ft_parse_width(&format, &info, ap);
			ft_parse_precision(&format, &info, ap);
			printed += ft_parse_type(&info, ap, *format);
		}
		else
			printed += write(1, format, 1);
		format++;
	}
	return (printed);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;

	va_start(ap, format);
	printed = ft_parse_symbols(format, ap);
	va_end(ap);
	return (printed);
}
