/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:44:12 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/02 18:58:18 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_malloc(t_mlx_info *info)
{
	int	i;

	i = -1;
	while (++i < WINDOW_HEIGHT)
		ft_memset(info->buf[i], 0, sizeof(int) * WINDOW_WIDTH);
	i = -1;
	while (++i < 8)
	{
		info->texture[i] = malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
		if (!info->texture[i])
			exit(1);
	}
	i = -1;
	while (++i < 8)
		ft_memset(info->texture[i], 0, sizeof(int) * TEXHEIGHT * TEXWIDTH);
	load_texture(info);
}

static int	convert_map_data(char data_map_elements)
{
	if (data_map_elements == ' ')
		return (-1);
	else if (data_map_elements == 'N' || data_map_elements == 'S' || \
			data_map_elements == 'E' || data_map_elements == 'W')
		return (2);
	else
		return (data_map_elements - '0');
}

void	copy_data_to_info(t_mlx_info *_info, t_map_data *_data)
{
	int	col;
	int	row;

	row = -1;
	_info->world_map = (int **)malloc(sizeof(int *) * \
						(_data->num_of_map_line + 1));
	if (!_info->world_map)
		exit(free_map_data(_data));
	while (++row < _data->num_of_map_line)
	{
		col = -1;
		while (_data->map[row][++col])
		_info->world_map[row] = (int *)malloc(sizeof(int) * (col + 1));
		if (!_info->world_map[row])
			exit(free_map_data(_data));
		col = -1;
		while (_data->map[row][++col])
			_info->world_map[row][col] = convert_map_data(_data->map[row][col]);
		_info->world_map[row][col] = -2;
	}
	_info->world_map[row] = NULL;
}

static void	player_start_position(t_mlx_info *info, t_map_data *data)
{
	info->posx = data->pos_x;
	info->posy = data->pos_y;
	if (data->player_face == 'N')
	{
		info->dirx = 1.0;
		info->diry = 0.0;
	}
	else if (data->player_face == 'S')
	{
		info->dirx = -1.0;
		info->diry = 0.0;
	}
	else if (data->player_face == 'W')
	{
		info->dirx = 0.0;
		info->diry = 1.0;
	}
	else if (data->player_face == 'E')
	{
		info->dirx = 0.0;
		info->diry = -1.0;
	}
}

void	init_mlx_info(t_mlx_info *info, t_map_data *data)
{
	info->mlx = mlx_init();
	player_start_position(info, data);
	info->planex = 0.0;
	info->planey = 0.66;
	info->re_buf = 0;
	info->movespeed = 0.05;
	info->rotspeed = 0.05;
	info->win = mlx_new_window(info->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx");
	info->img.img = mlx_new_image(info->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, \
									&info->img.size_l, &info->img.endian);
	info->texture = malloc(sizeof(int *) * 8);
	if (!info->texture)
		exit(1);
	info->key.key_w = 0;
	info->key.key_a = 0;
	info->key.key_s = 0;
	info->key.key_d = 0;
	info->key.key_left_arrow = 0;
	info->key.key_right_arrow = 0;
}
