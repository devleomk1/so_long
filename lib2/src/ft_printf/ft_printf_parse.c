/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:28:38 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 16:40:26 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		skip_atoi(const char **s)
{
	int	i;

	i = 0;
	while (ft_isdigit(**s))
		i = i * 10 + *((*s)++) - '0';
	return (i);
}

void	ft_parse_flag(const char **format, t_info *info)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '0')
			info->zero = ENABLE;
		else
		{
			if (info->zero == ENABLE)
				info->zero = DISABLE;
			info->minus = ENABLE;
		}
		(*format)++;
	}
}

void	ft_parse_width(const char **format, t_info *info, va_list ap)
{
	if (ft_isdigit(**format) == TRUE)
		info->width = skip_atoi(format);
	else if (**format == '*')
	{
		(*format)++;
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->width = -(info->width);
			info->minus = ENABLE;
			if (info->zero == ENABLE)
				info->zero = DISABLE;
		}
	}
}

void	ft_parse_precision(const char **format, t_info *info, va_list ap)
{
	if (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
			info->precision = skip_atoi(format);
		else if (**format == '*')
		{
			(*format)++;
			info->precision = va_arg(ap, int);
		}
		else
			info->dot_only = ENABLE;
		if (info->precision < 0)
			info->precision = -1;
	}
}

int		ft_parse_type(t_info *info, va_list ap, const char type)
{
	int	printed;

	printed = 0;
	if (type == 'c')
		printed += ft_print_char(info, ap);
	else if (type == '%')
		printed += ft_print_percent(info);
	else if (type == 's')
		printed += ft_print_string(info, ap);
	else if (type == 'd' || type == 'i')
		printed = print_di(info, ap);
	else if (type == 'u')
		printed = print_u(info, ap);
	else if (type == 'x' || type == 'X')
		printed = print_xx(info, ap, type);
	else if (type == 'p')
		printed = print_p(info, ap);
	return (printed);
}
