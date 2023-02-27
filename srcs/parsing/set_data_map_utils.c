/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:12:34 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/26 21:13:14 by seowoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*check_identifier(char *str, int *value_start_index)
{
	int		i;
	int		j;
	int		tmp_i;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] && str[i] == ' ')
		++i;
	while (str[i + j] && str[i + j] != ' ')
		++j;
	tmp_i = i;
	while (str[i + j] && str[i + j] == ' ')
		++i;
	*value_start_index = i + j;
	ret = (char *)malloc(sizeof(char) * (j + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[tmp_i] && str[tmp_i] != ' ')
	{
		ret[i] = str[tmp_i];
		++i;
		++tmp_i;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_texture_path(t_map_data *_data, char *str, int path_start_index)
{
	int		tmp_index;
	int		len;
	char	*ret;

	len = 0;
	tmp_index = path_start_index - 1;
	while (str[++tmp_index])
		if (str[tmp_index] != ' ')
			++len;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	len = 0;
	while (str[path_start_index])
	{
		if (str[path_start_index] != ' ')
		{
			ret[len] = str[path_start_index];
			++len;
		}
		++path_start_index;
	}
	ret[len] = '\0';
	++(_data->num_of_data_except_map);
	return (ret);
}

int	get_floor_rgb(t_map_data *_data, char *str, int rgb_start_index)
{
	char	**_tmp;
	int		i;
	int		j;

	i = -1;
	_tmp = ft_split(&str[rgb_start_index], ", ");
	while (_tmp[++i])
		if (i > 2)
			return (ft_free_double_string(_tmp, 0));
	i = -1;
	while (_tmp[++i])
	{
		j = -1;
		while (_tmp[i][++j])
			if (!ft_isdigit(_tmp[i][j]))
				return (ft_free_double_string(_tmp, 0));
		if (i == 0)
			_data->floor_r = ft_atoi(_tmp[i]);
		else if (i == 1)
			_data->floor_g = ft_atoi(_tmp[i]);
		else
			_data->floor_b = ft_atoi(_tmp[i]);
	}
	++(_data->num_of_data_except_map);
	return (ft_free_double_string(_tmp, 1));
}

int	get_ceiling_rgb(t_map_data *_data, char *str, int rgb_start_index)
{
	char	**_tmp;
	int		i;
	int		j;

	i = -1;
	_tmp = ft_split(&str[rgb_start_index], ", ");
	while (_tmp[++i])
		if (i > 2)
			return (ft_free_double_string(_tmp, 0));
	i = -1;
	while (_tmp[++i])
	{
		j = -1;
		while (_tmp[i][++j])
			if (!ft_isdigit(_tmp[i][j]))
				return (ft_free_double_string(_tmp, 0));
		if (i == 0)
			_data->ceiling_r = ft_atoi(_tmp[i]);
		else if (i == 1)
			_data->ceiling_g = ft_atoi(_tmp[i]);
		else
			_data->ceiling_b = ft_atoi(_tmp[i]);
	}
	++(_data->num_of_data_except_map);
	return (ft_free_double_string(_tmp, 1));
}

int	check_data_is_full(t_map_data *_data)
{
	if (_data->num_of_data_except_map != 6)
		return (0);
	++(_data->num_of_map_line);
	return (1);
}
