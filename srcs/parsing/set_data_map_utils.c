/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:12:34 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/03 20:14:25 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**check_rgb_form(char *str)
{
	char	**ret;
	int		i;
	int		num_of_comma;

	i = -1;
	num_of_comma = 0;
	while (str[++i])
		if (str[i] == ',')
			++num_of_comma;
	if (num_of_comma != 2)
		return (NULL);
	ret = ft_split(str, ", ");
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (ret[++i])
		;
	if (i != 3)
	{
		ft_free_double_string(ret, 0);
		return (NULL);
	}
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
		++len;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	len = 0;
	while (str[path_start_index])
	{
		ret[len] = str[path_start_index];
		++len;
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

	_tmp = check_rgb_form(&str[rgb_start_index]);
	if (!_tmp)
		return (print_error_msg("Check floor's rgb form", 0));
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
	_data->bool_floor = 1;
	return (ft_free_double_string(_tmp, 1));
}

int	get_ceiling_rgb(t_map_data *_data, char *str, int rgb_start_index)
{
	char	**_tmp;
	int		i;
	int		j;

	_tmp = check_rgb_form(&str[rgb_start_index]);
	if (!_tmp)
		return (print_error_msg("Check ceiling's rgb form", 0));
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
	_data->bool_ceiling = 1;
	return (ft_free_double_string(_tmp, 1));
}

int	check_data_is_full(t_map_data *_data)
{
	if (_data->num_of_data_except_map != 6)
		return (0);
	++(_data->num_of_map_line);
	return (1);
}
