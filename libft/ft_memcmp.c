/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:55:43 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/17 05:24:05 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*_s1;
	unsigned char	*_s2;
	size_t			i;

	i = 0;
	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (_s1[i] != _s2[i])
			return (_s1[i] - _s2[i]);
		else
			i++;
	}
	return (0);
}
