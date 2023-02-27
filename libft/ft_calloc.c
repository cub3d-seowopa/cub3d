/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:26:08 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/20 19:38:52 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	ckt;

	ckt = size * count;
	if (count != 0)
	{
		if (size != ckt / count)
			return (NULL);
	}
	ret = (void *)malloc(count * size);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, count * size);
	return (ret);
}
