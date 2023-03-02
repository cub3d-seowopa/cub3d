/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:15:22 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/02 17:11:56 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_map_data(t_map_data *_data)
{
	int	i;

	if (!_data)
		return (-1);
	i = -1;
	if (_data->north_tex_path)
		free(_data->north_tex_path);
	if (_data->south_tex_path)
		free(_data->south_tex_path);
	if (_data->east_tex_path)
		free(_data->east_tex_path);
	if (_data->west_tex_path)
		free(_data->west_tex_path);
	if (_data->map)
	{
		while (_data->map[++i])
			free(_data->map[i]);
		free(_data->map);
	}
	free(_data);
	_data = NULL;
	return (1);
}
