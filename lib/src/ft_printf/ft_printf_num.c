/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:24:19 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 16:40:26 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	print_di(t_info *info, va_list ap)
{
	int			printed;
	long long	num;

	info->num_base = 10;
	num = va_arg(ap, int);
	if (num < 0)
	{
		info->num_sign = -1;
		num = -num;
		(info->width)--;
	}
	printed = print_num(info, num);
	return (printed);
}

int	print_u(t_info *info, va_list ap)
{
	int			printed;
	long long	num;

	info->num_base = 10;
	num = va_arg(ap, unsigned int);
	printed = print_num(info, num);
	return (printed);
}

int	print_xx(t_info *info, va_list ap, char type)
{
	int			printed;
	long long	num;

	if (type == 'x')
		info->locass = SMALL;
	info->num_base = 16;
	num = va_arg(ap, unsigned int);
	printed = print_num(info, num);
	return (printed);
}

int	print_p(t_info *info, va_list ap)
{
	int			printed;
	long long	num;

	info->address = ENABLE;
	info->locass = SMALL;
	info->width -= 2;
	info->num_base = 16;
	num = (unsigned long)va_arg(ap, void *);
	printed = print_num(info, num);
	return (printed);
}
