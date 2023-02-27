/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:33:49 by chanwopa          #+#    #+#             */
/*   Updated: 2022/11/13 15:58:35 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle && len == 0)
		return (0);
	if (!*needle || len == 0)
		return ((char *)haystack);
	while (*haystack && len >= ft_strlen(needle))
	{
		if (*haystack == *needle && \
			!ft_strncmp(haystack, needle, ft_strlen(needle)))
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
