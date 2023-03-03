/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:05:02 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/17 08:53:28 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_num(long long int num)
{
	long long int	ret;

	ret = 0;
	if (num <= 0)
	{
		num *= -1;
		ret = 1;
	}
	while (num > 0)
	{
		num /= 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				size;
	long long int	n1;

	n1 = n;
	size = cnt_num(n1);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ret[size] = '\0';
	if (n1 < 0)
	{
		ret[0] = '-';
		n1 *= -1;
	}
	else if (n1 == 0)
		ret[0] = '0';
	while (n1 > 0)
	{
		ret[size - 1] = (n1 % 10) + 48;
		n1 /= 10;
		size -= 1;
	}
	return (ret);
}
