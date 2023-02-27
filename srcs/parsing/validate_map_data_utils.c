/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_data_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:56:52 by seowoo            #+#    #+#             */
/*   Updated: 2023/02/27 17:41:29 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_boundary_wall(char *map_line, int index, int max_line)
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

int	check_all_neighbor(t_map_data *_data)
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
