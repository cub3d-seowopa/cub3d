/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:17:47 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/24 17:03:44 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*memory_set(int index, int ckt)
{
	char	*str;

	if (ckt == 1)
		str = (char *)malloc(sizeof(char) * (index + 1));
	else
		str = (char *)malloc(sizeof(char) * index);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*make_temp(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 1);
	if (ret == NULL)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}
