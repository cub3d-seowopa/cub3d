/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:28:32 by chanwopa          #+#    #+#             */
/*   Updated: 2022/11/14 01:03:00 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long long input)
{
	int	len;

	len = 0;
	if (input == 0)
		return (1);
	if (input < 0)
	{
		input *= -1;
		len++;
	}
	while (input > 0)
	{
		input /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long long	num;
	int			len;

	num = n;
	len = ft_intlen(num);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	*(ptr + len) = '\0';
	if (num == 0)
		*ptr = '0';
	if (num < 0)
	{
		*ptr = '-';
		num *= -1;
	}
	while (num > 0)
	{
		len--;
		*(ptr + len) = (char)(num % 10 + '0');
		num /= 10;
	}
	return (ptr);
}
