/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_data_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:56:52 by seowoo            #+#    #+#             */
/*   Updated: 2023/03/02 21:14:02 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_boundary_wall(char *map_line, int index, int max_line)
{
	int	len;
	int	start_wall;

	len = -1;
	start_wall = 0;
	if (index == 0 || index == max_line - 1)
	{
		while (map_line[++len])
			if (map_line[len] != ' ' && map_line[len] != '1')
				return (print_error_msg("Check map's first endline", 0));
	}
	else
	{
		while (map_line[++len])
		{
			if (map_line[len] == '1' && start_wall == 0)
				start_wall = len;
		}
		if (map_line[start_wall] != '1' && map_line[max_line] != '1')
			return (print_error_msg("Check map's mid", 0));
	}
	return (1);
}

static int	check_all_neighbor(t_map_data *_data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < _data->num_of_map_line - 1)
	{
		j = -1;
		while (_data->map[i][++j])
		{
			if (_data->map[i][j] == ' ')
			{
				if (_data->map[i + 1][j] == '0' || _data->map[i][j + 1] == '0')
					return (print_error_msg("No wall", 0));
			}
			else if (_data->map[i][j] == '0')
			{
				if (_data->map[i + 1][j] == ' ' || _data->map[i][j + 1] == ' ')
					return (print_error_msg("No wall", 0));
			}
		}
	}
	return (1);
}

static int	check_map_elements(t_map_data *_data)
{
	int		i;
	int		j;
	char	tmp;

	i = -1;
	while (_data->map[++i])
	{
		j = -1;
		while (_data->map[i][++j])
		{
			tmp = _data->map[i][j];
			if (tmp != '0' && tmp != ' ' && tmp != '1' && tmp != 'N' \
				&& tmp != 'S' && tmp != 'E' && tmp != 'W')
				return (print_error_msg("Some wrong elements in the map.", 0));
			if (tmp == 'N' || tmp == 'S' || tmp == 'E' || tmp == 'W')
				put_player_init_status(_data, i, j, tmp);
			if (_data->num_of_player > 1)
				return (print_error_msg("More than one player in the map.", 0));
		}
	}
	if (_data->num_of_player != 1)
		return (print_error_msg("No player in the map.", 0));
	return (1);
}

int	check_path_is_valided(t_map_data *_data)
{
	int	fd;

	fd = 0;
	fd = open(_data->north_tex_path, O_RDONLY);
	if (fd < 0)
		return (print_error_msg("North texture path is invaild", 0));
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
		return (print_error_msg("Only one line in the map", 0));
	else if (!check_map_elements(_data))
		return (0);
	i = -1;
	while (_data->map[++i])
		if (!is_boundary_wall(_data->map[i], i, _data->num_of_map_line))
			return (0);
	if (!check_all_neighbor(_data))
		return (0);
	return (1);
}
