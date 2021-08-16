/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_tobase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:17:02 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/23 19:40:35 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * num		= 1234
 * num_box	= [4][3][2][1]
 * len		= 4
 */
int	ft_num_tobase(int *num_box, long long num, unsigned int base)
{
	int	len;

	len = 0;
	{
		while (num != 0)
		{
			num_box[len++] = num % base;
			num = num / base;
		}
	}
	return (len);
}
