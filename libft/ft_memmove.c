/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:34:19 by chanwopa          #+#    #+#             */
/*   Updated: 2022/11/12 16:59:15 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	int				sign;

	ptr_d = (unsigned char *)dst;
	ptr_s = (unsigned char *)src;
	sign = 1;
	if (!ptr_d && !ptr_s)
		return (NULL);
	if (dst >= src)
	{
		ptr_d += len - 1;
		ptr_s += len - 1;
		sign = -1;
	}
	while (len-- > 0)
	{
		*ptr_d = *ptr_s;
		ptr_d += sign;
		ptr_s += sign;
	}
	return (dst);
}
