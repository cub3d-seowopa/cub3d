/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:31:18 by chanwopa          #+#    #+#             */
/*   Updated: 2022/11/14 15:20:51 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", sizeof(char) * 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", sizeof(char));
		n *= -1;
	}
	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, sizeof(char));
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, sizeof(char));
	}
}
