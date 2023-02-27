/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:58:28 by chanwopa          #+#    #+#             */
/*   Updated: 2022/11/12 17:09:31 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	copied_len;

	if ((!dst || !src) && !dstsize)
		return (0);
	src_len = ft_strlen(src);
	copied_len = 0;
	while (*src && copied_len + 1 < dstsize)
	{
		*dst = *src;
		dst++;
		src++;
		copied_len++;
	}
	if (dstsize)
		*dst = '\0';
	return (src_len);
}
