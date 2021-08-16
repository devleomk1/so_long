/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:43:30 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 16:31:19 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# include "libft.h"

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define ENABLE 1
# define DISABLE 0
# define SMALL 32

# define DIGITS "0123456789ABCDEF"

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			dot_only;
	int			locass;
	int			num_base;
	int			num_sign;
	int			address;
}				t_info;

/*
*****************************   MAIN FUNCTION   *******************************
*/

void			init_struct(t_info *info);
int				ft_parse_symbols(const char *format, va_list ap);
int				ft_printf(const char *format, ...);

/*
*****************************   PARSE FUNCTION   ******************************
*/

int				skip_atoi(const char **s);
void			ft_parse_flag(const char **format, t_info *info);
void			ft_parse_width(const char **format, t_info *info, va_list ap);
void			ft_parse_precision
				(const char **format, t_info *info, va_list ap);
int				ft_parse_type(t_info *info, va_list ap, const char type);

/*
*****************************   PRINT FUNCTION   *******************************
*/

int				ft_print_char(t_info *info, va_list ap);
int				ft_print_percent(t_info *info);
int				ft_print_string(t_info *info, va_list ap);
int				print_di(t_info *info, va_list ap);
int				print_u(t_info *info, va_list ap);
int				print_xx(t_info *info, va_list ap, char type);
int				print_p(t_info *info, va_list ap);
int				ft_print_num(t_info *info, va_list ap, const char type);
int				get_max(int a, int b);
int				ft_putchar_len(char c, int *len);
int				num_itoa(t_info *info, char *num_box, long long num);
int				print_sign(t_info *info);
int				print_num(t_info *info, long long num);

#endif
