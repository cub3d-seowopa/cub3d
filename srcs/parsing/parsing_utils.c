/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:26:22 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/26 23:22:24 by seowoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_end(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_my_strstr(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] == str2[0])
		{
			if (check_end(&str1[i], &str2[0]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	free_strings(char *str1, char *str2, int return_value)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (return_value);
}

int	ft_free_double_string(char **str, int ret)
{
	int	i;

	if (!str)
		return (ret);
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (ret);
}

int	check_rgb(int rgb)
{
	if (rgb <= 255 && rgb >= 0)
		return (1);
	return (0);
}

void	print_map_data(t_map_data *_data)
{
	printf("NORTH : %s\n", _data->north_tex_path);
	printf("SOUTH : %s\n", _data->south_tex_path);
	printf("EAST : %s\n", _data->east_tex_path);
	printf("WEST : %s\n", _data->west_tex_path);
	printf("Floor RGB : [%d] [%d] [%d]\n", _data->floor_r, _data->floor_g, _data->floor_b);
	printf("Ceiling RGB : [%d] [%d] [%d]\n", _data->ceiling_r, _data->ceiling_g, _data->ceiling_b);
	printf("\n\tMAP\n");
	for(int i = 0; _data->map[i] != NULL; i++)
		printf("[%d] : %s\n", i, _data->map[i]);
}
