/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:44:16 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/26 21:16:34 by seowoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_map(char *str, t_map_data *_data)
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

int	put_map_data(char *str, t_map_data *_data)
{
	char	*identifier;
	int		i;

	i = 0;
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
	else if (ft_strncmp(identifier, "F", 2) == 0)
		get_floor_rgb(_data, str, i);
	else if (ft_strncmp(identifier, "C", 2) == 0)
		get_ceiling_rgb(_data, str, i);
	else
		return (free_strings(str, identifier, -1));
	return (free_strings(str, identifier, 1));
}

int	read_map_file(t_map_data *_data, const char *path)
{
	int		fd;
	char	*tmp_buf;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error_msg("Failed to Read File", 0));
	tmp_buf = get_next_line(fd);
	while (tmp_buf)
	{
		if (ft_strncmp(tmp_buf, "\0", 1) == 0)
			free(tmp_buf);
		else if (check_data_is_full(_data))
			make_map(tmp_buf, _data);
		else
			if (put_map_data(tmp_buf, _data) == -1)
				return (print_error_msg("Wrong elements", 0));
		tmp_buf = get_next_line(fd);
	}
	close(fd);
	print_map_data(_data);
	if (!check_map_data_vaildation(_data))
		return (print_error_msg("Invaild map file", 0));
	return (1);
}
