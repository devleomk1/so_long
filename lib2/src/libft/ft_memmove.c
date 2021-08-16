/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 02:27:48 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/23 19:29:41 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	if (dst == src || len == 0)
		return (dst);
	i = 0;
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (dst < src)
	{
		while (i++ < len)
			new_dst[i - 1] = new_src[i - 1];
	}
	else
	{
		while (i < len)
		{
			new_dst[len - i - 1] = new_src[len - i - 1];
			i++;
		}
	}
	return (dst);
}
