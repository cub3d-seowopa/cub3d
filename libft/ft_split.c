/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:39:34 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/26 20:37:44 by seowoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
	return (NULL);
}

static int	bool_sep(char str, char *c)
{
	int	i;

	i = -1;
	while (c[++i])
		if (str == c[i])
			return (1);
	return (0);
}

static char	*put_word(char const *str, char *c)
{
	char		*word;
	size_t		word_len;
	size_t		i;
	const char	*temp;

	temp = str;
	word_len = 0;
	while (*str && !bool_sep(*str, c))
	{
		word_len++;
		str++;
	}
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = *temp;
		i++;
		temp++;
	}
	word[i] = '\0';
	return (word);
}

static size_t	count_word(char const *str, char *c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && bool_sep(str[i], c))
			i++;
		if (str[i])
			cnt++;
		while (str[i] && !bool_sep(str[i], c))
			i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char *c)
{
	char	**split;
	size_t	j;

	j = 0;
	if (s == NULL)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (split == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && bool_sep(*s, c))
			s++;
		if (*s)
		{
			split[j] = put_word(s, c);
			if (split[j] == NULL)
				return (ft_free(split));
			j++;
		}
		while (*s && !bool_sep(*s, c))
			s++;
	}
	split[j] = NULL;
	return (split);
}
