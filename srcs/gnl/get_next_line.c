/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:10:34 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/24 19:23:45 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*gnl_split(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	i++;
	if (ret == NULL)
		return (NULL);
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = '\0';
	free (str);
	return (ret);
}

int	ckt_new_line(const char *buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*make_line(int fd, char *buf, char *x_buf)
{
	int		ckt;
	char	*temp;

	ckt = 1;
	while (ckt != 0)
	{
		ckt = read(fd, buf, BUFFER_SIZE);
		if (ckt == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ckt] = '\0';
		temp = x_buf;
		if (temp == NULL)
			temp = make_temp();
		x_buf = ft_strjoin(temp, buf);
		free(temp);
		if (ckt_new_line(buf))
			break ;
	}
	free (buf);
	return (x_buf);
}

static char	*only_one_line(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			break ;
		i++;
	}
	if (str[0] == '\0')
		return (NULL);
	ret = memory_set(i, 0);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*x_buf;
	char		*buf;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	x_buf = make_line(fd, buf, x_buf);
	if (x_buf == NULL)
		return (NULL);
	ret = only_one_line(x_buf);
	x_buf = gnl_split(x_buf);
	return (ret);
}
