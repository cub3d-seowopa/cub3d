/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:39:12 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/19 13:39:47 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*_s;
	size_t			i;

	i = 0;
	_s = (unsigned char *)s;
	while (i < n)
	{
		if (_s[i] == (unsigned char)c)
			return (&_s[i]);
		i++;
	}
	return (NULL);
}
