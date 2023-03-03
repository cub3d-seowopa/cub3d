/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:37:41 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/18 10:11:59 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char	*_dst;
	unsigned char	*_src;
	size_t			i;

	i = -1;
	if (dst == NULL && src == NULL)
		return (NULL);
	_dst = (unsigned char *)dst;
	_src = (unsigned char *)src;
	if (_dst < _src)
	{
		while (++i < size)
			_dst[i] = _src[i];
	}
	else
	{
		while (++i < size)
			_dst[size - 1 - i] = _src[size - 1 - i];
	}
	return (dst);
}
