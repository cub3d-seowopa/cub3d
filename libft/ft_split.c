/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:29:01 by chanwopa          #+#    #+#             */
/*   Updated: 2022/11/14 15:34:08 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_split_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

size_t	ft_get_nonsep_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) && *(s + len) != c)
		len++;
	return (len);
}

char	**ft_free_split(char **strs)
{
	size_t	index;

	index = 0;
	while (*(strs + index))
	{
		free(*(strs + index));
		*(strs + index) = NULL;
		index++;
	}
	free (strs);
	strs = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_get_split_count(s, c) + 1));
	if (!strs)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			*(strs + index) = ft_substr(s, 0, ft_get_nonsep_len(s, c));
			if (!(*(strs + index)))
				return (ft_free_split(strs));
			index++;
			s += ft_get_nonsep_len(s, c);
		}
	}
	*(strs + index) = NULL;
	return (strs);
}
