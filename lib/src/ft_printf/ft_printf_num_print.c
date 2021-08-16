/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:11:49 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 16:40:26 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_putchar_len(char c, int *len)
{
	int	i;

	i = 0;
	while ((*len)-- > 0)
		i += write(1, &c, 1);
	return (i);
}

int	num_itoa(t_info *info, char *num_box, long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		num_box[len++] = '0';
	else
	{
		while (num != 0)
		{
			num_box[len++] = (DIGITS[num % info->num_base]) | info->locass;
			num = num / info->num_base;
		}
	}
	return (len);
}

int	print_sign(t_info *info)
{
	int	printed;

	printed = 0;
	if (info->num_sign == -1)
		printed += write(1, "-", 1);
	if (info->address == ENABLE)
		printed += write(1, "0x", 2);
	return (printed);
}

int	print_num(t_info *info, long long num)
{
	int			len;
	int			gap;
	int			printed;
	long long	tmp_num;
	char		num_box[21];

	printed = 0;
	tmp_num = num;
	len = num_itoa(info, num_box, num);
	if (tmp_num == 0 && (info->precision == 0 || info->dot_only == ENABLE))
		len = 0;
	gap = info->width - get_max(info->precision, len);
	if ((info->minus == DISABLE && gap > 0) && (!(info->zero == ENABLE &&
	info->precision < 0) || info->dot_only == ENABLE))
		printed += ft_putchar_len(' ', &gap);
	info->precision = get_max(info->precision, len);
	printed += print_sign(info);
	if (info->zero == ENABLE)
		printed += ft_putchar_len('0', &gap);
	info->precision -= len;
	printed += ft_putchar_len('0', &info->precision);
	while (len-- > 0)
		printed += write(1, &num_box[len], 1);
	printed += ft_putchar_len(' ', &gap);
	return (printed);
}
