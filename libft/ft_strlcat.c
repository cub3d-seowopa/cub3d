/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:58:36 by chanwopa          #+#    #+#             */
/*   Updated: 2022/11/14 15:10:24 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		dest_idx;
	int		src_idx;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	dest_idx = dest_len;
	src_idx = 0;
	while (*(src + src_idx) && (src_idx + dest_len + 1) < size)
	{
		*(dest + dest_idx) = *(src + src_idx);
		dest_idx++;
		src_idx++;
	}
	*(dest + dest_idx) = '\0';
	if (dest_len < size)
		return (src_len + dest_len);
	else
		return (src_len + size);
}
