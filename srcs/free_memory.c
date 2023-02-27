/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:15:22 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/24 23:16:34 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx_info(t_mlx_info *_info)
{
	// if (_info->mlx_ptr)
	// 	free(_info->mlx_ptr);
	// if (_info->win_ptr)
	// 	free(_info->win_ptr);
	mlx_destroy_window(_info->mlx_ptr, _info->win_ptr);
	free(_info);
	_info = NULL;
	exit(0);
}

void	free_map_data(t_map_data *_data)
{
	int	i;

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
}

void	free_all_memory(t_mlx_info *_info, t_map_data *_data)
{
	if (_data)
		free_map_data(_data);
	if (_info)
		free_mlx_info(_info);
}
