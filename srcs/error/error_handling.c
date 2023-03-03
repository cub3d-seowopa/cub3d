/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:26:43 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/03 15:24:04 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error_msg(char *message, int _errno)
{
	ft_putstr_fd("Error\n----> ", 2);
	ft_putstr_fd(RED, 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd(WHITE, 2);
	return (_errno);
}

static int	free_int(int **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
	return (1);
}

int	close_window(t_mlx_info *info)
{
	free_int(info->texture);
	free_int(info->world_map);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

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
