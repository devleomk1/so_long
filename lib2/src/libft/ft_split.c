/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 07:44:44 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/23 19:29:41 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	get_str_count(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i] != '\0')
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else if (str[i] != '\0')
			i++;
	}
	return (count);
}

static void	*free_malloc(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static void	do_split(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			str[j] = (char *)malloc(sizeof(char) * (i - start + 1));
			if (str[j] == NULL)
			{
				free_malloc(str);
				return ;
			}
			ft_strlcpy(str[j], &s[start], i - start + 1);
			j++;
		}
		else if (s[i] != '\0')
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	str_count;

	if (s == NULL)
		return (NULL);
	str_count = get_str_count(s, c);
	str = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (str == NULL)
		return (NULL);
	str[str_count] = NULL;
	if (str_count == 0)
		return (str);
	do_split(s, c, str);
	return (str);
}
