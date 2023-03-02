/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:44:16 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/02 17:58:58 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*check_identifier(char *str, int *value_start_index)
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
		ret[i++] = str[tmp_i++];
	ret[i] = '\0';
	return (ret);
}

static void	make_map(char *str, t_map_data *_data)
{
	char	**tmp_map;
	int		i;

	tmp_map = _data->map;
	_data->map = (char **)malloc(sizeof(char *) * (_data->num_of_map_line + 1));
	if (!_data->map)
		return ;
	i = 0;
	while (tmp_map && tmp_map[i])
	{
		_data->map[i] = ft_strdup(tmp_map[i]);
		i++;
	}
	_data->map[i++] = str;
	_data->map[i] = NULL;
	ft_free_double_string(tmp_map, 1);
}

static int	put_map_data(char *str, t_map_data *_data)
{
	char	*identifier;
	int		i;
	int		ret_code;

	i = 0;
	ret_code = 1;
	identifier = check_identifier(str, &i);
	if (identifier == NULL)
		return (free_strings(str, NULL, 0));
	else if (ft_strncmp(identifier, "NO", 3) == 0 && !_data->north_tex_path)
		_data->north_tex_path = get_texture_path(_data, str, i);
	else if (ft_strncmp(identifier, "SO", 3) == 0 && !_data->south_tex_path)
		_data->south_tex_path = get_texture_path(_data, str, i);
	else if (ft_strncmp(identifier, "WE", 3) == 0 && !_data->west_tex_path)
		_data->west_tex_path = get_texture_path(_data, str, i);
	else if (ft_strncmp(identifier, "EA", 3) == 0 && !_data->east_tex_path)
		_data->east_tex_path = get_texture_path(_data, str, i);
	else if (ft_strncmp(identifier, "F", 2) == 0 && !_data->bool_floor)
		ret_code = get_floor_rgb(_data, str, i);
	else if (ft_strncmp(identifier, "C", 2) == 0 && !_data->bool_ceiling)
		ret_code = get_ceiling_rgb(_data, str, i);
	else
		return (free_strings(str, identifier, -1));
	return (free_strings(str, identifier, ret_code));
}

int	read_map_file(t_map_data *_data, const char *map_path)
{
	int		fd;
	char	*tmp_buf;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (print_error_msg("Failed to Read File", 0));
	tmp_buf = get_next_line(fd);
	while (tmp_buf)
	{
		if (ft_strncmp(tmp_buf, "\0", 1) == 0)
		{
			free(tmp_buf);
			if (_data->num_of_map_line != 0)
				return (print_error_msg("Map can not be seperated", close(fd)));
		}
		else if (check_data_is_full(_data))
			make_map(tmp_buf, _data);
		else
			if (put_map_data(tmp_buf, _data) <= 0)
				return (print_error_msg("Wrong elements", close(fd)));
		tmp_buf = get_next_line(fd);
	}
	if (!check_map_data_vaildation(_data, fd))
		return (print_error_msg("Invaild map file", 0));
	return (1);
}
