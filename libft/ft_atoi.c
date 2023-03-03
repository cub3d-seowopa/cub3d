/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:28:03 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/19 15:48:35 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ckt_max_min(long nbr, long next_nbr, int minus)
{
	long	cmp;

	cmp = next_nbr / 10;
	if ((nbr != cmp) && minus == 1)
		return (1);
	else if ((nbr != cmp) && minus == -1)
		return (2);
	return (0);
}

static int	cktspace(const char *str)
{
	int	i;

	i = 0;
	while (!(str[i] == '+' || str[i] == '-'
			|| (str[i] >= 48 && str[i] == 57)))
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
			i++;
		else
			return (i);
	}
	return (i);
}

static int	cktminus(const char str)
{
	if (str == '+')
		return (1);
	else if (str == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	res;
	long	diff;

	i = cktspace(str);
	diff = 0;
	res = 0;
	minus = cktminus(str[i]);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		diff = res;
		res = (res * 10) + (str[i] - 48);
		if (ckt_max_min(diff, res, minus) == 1)
			return (-1);
		else if (ckt_max_min(diff, res, minus) == 2)
			return (0);
		i++;
	}
	res = res * minus;
	return ((int)res);
}
