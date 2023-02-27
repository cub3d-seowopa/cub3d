/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:30:47 by chanwopa          #+#    #+#             */
/*   Updated: 2022/11/12 15:59:51 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	if (!dst && !src)
		return (NULL);
	ptr_d = (unsigned char *)dst;
	ptr_s = (unsigned char *)src;
	while (n > 0)
	{
		*ptr_d = *ptr_s;
		ptr_d++;
		ptr_s++;
		n--;
	}
	return (dst);
}
