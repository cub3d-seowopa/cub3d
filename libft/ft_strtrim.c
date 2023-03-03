/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:57:55 by seowokim          #+#    #+#             */
/*   Updated: 2022/05/19 13:45:01 by seowokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ckt_front(char const *s1, char const *set)
{
	int	front;
	int	i;

	i = -1;
	front = 0;
	while (set[++i] && s1[front])
	{
		if (s1[front] == set[i])
		{
			front++;
			i = -1;
		}
	}
	return (front);
}

static int	ckt_back(char const *s1, char const *set, int front, int back)
{
	int	i;

	i = -1;
	while (set[++i] && back > front)
	{
		if (s1[back] == set[i])
		{
			back--;
			i = -1;
		}
	}
	return (back);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return ((char *)s1);
	front = ckt_front(s1, set);
	back = ft_strlen(s1) - 1;
	back = ckt_back(s1, set, front, back);
	ret = (char *)malloc(sizeof(char) * (back - front + 2));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, &s1[front], (size_t)(back - front + 2));
	return (ret);
}
