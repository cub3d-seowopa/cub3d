/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:50:11 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/18 01:39:44 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*_s1;
	unsigned char	*_s2;

	i = 0;
	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	while ((_s1[i] || _s2[i]) && i < n)
	{
		if (_s1[i] != _s2[i])
			return (_s1[i] - _s2[i]);
		else
			i++;
	}
	return (0);
}
