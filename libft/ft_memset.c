/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:52:14 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/19 20:37:58 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*_b;
	size_t			i;

	i = 0;
	_b = (unsigned char *)b;
	while (i < len)
		_b[i++] = (unsigned char)c;
	return (b);
}
