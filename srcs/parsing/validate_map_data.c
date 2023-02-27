/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:19:11 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/26 23:07:20 by seowoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_path_is_valided(t_map_data *_data)
{
	int	fd;

	fd = 0;
	fd = open(_data->north_tex_path, O_RDONLY);
	if (fd < 0)
		return (print_error_msg("Nort path is invaild", 0));
	close(fd);
	fd = open(_data->south_tex_path, O_RDONLY);
	if (fd < 0)
		return (print_error_msg("South texture path is invaild", 0));
	close(fd);
	fd = open(_data->west_tex_path, O_RDONLY);
	if (fd < 0)
		return (print_error_msg("West texture path is invaild", 0));
	close(fd);
	fd = open(_data->east_tex_path, O_RDONLY);
	if (fd < 0)
		return (print_error_msg("East texture path is invaild", 0));
	close(fd);
	return (1);
}

int	check_map(t_map_data *_data)
{
	int	i;

	if (_data->num_of_map_line <= 1)
		return (0);
	i = -1;
	while (_data->map[++i])
		if (!is_boundary_wall(_data->map[i], i, _data->num_of_map_line))
			return (0);
	if (!check_all_neighbor(_data))
		return (0);
	return (1);
}

int	check_map_data_vaildation(t_map_data *_data)
{
	if (!(check_rgb(_data->ceiling_r) && check_rgb(_data->ceiling_g) \
		&& check_rgb(_data->ceiling_b) && check_rgb(_data->floor_r) \
		&& check_rgb(_data->floor_g) && check_rgb(_data->floor_b)))
		return (print_error_msg("RGB is out of range", 0));
	//else if (!(_data->north_tex_path && _data->south_tex_path && \
	//	_data->west_tex_path && _data ->east_tex_path))
	//	return (print_error_msg("There is empty texture path", 0));
	//else if (!check_path_is_valided(_data))
	//	return (print_error_msg("Invaild texture path", 0));
	else if (!check_map(_data))
		return (print_error_msg("Invaild map", 0));
	return (1);
}
