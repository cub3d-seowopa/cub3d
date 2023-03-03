/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:05:18 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/18 09:19:26 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_val(const char *str1, const char *str2, size_t len)
{
	size_t	i;

	i = 0;
	while (str2[i])
	{
		if (i >= len)
			return (0);
		if (str1[i] == str2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			if (check_val(&haystack[i], &needle[0], len - i))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
