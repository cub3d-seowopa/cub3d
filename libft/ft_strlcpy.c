/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:42:40 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/10 18:33:18 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dst_size == 0)
		return (src_len);
	while (i < src_len && i + 1 < dst_size)
	{
		dst[i] = src[i];
		i++;
	}
	if (dst_size > 0)
		dst[i] = '\0';
	return (src_len);
}
