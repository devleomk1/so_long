/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:22:04 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 16:40:26 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print_string(t_info *info, va_list ap)
{
	int			len;
	int			printed;
	const char	*s;

	printed = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (info->precision < len && info->precision > 0)
		len = info->precision;
	else if (info->precision == 0 || info->dot_only == ENABLE)
		len = 0;
	if (info->minus == DISABLE)
		while (len < (info->width)--)
			printed += write(1, " ", 1);
	printed += write(1, s, len);
	while (len < (info->width)--)
		printed += write(1, " ", 1);
	return (printed);
}
