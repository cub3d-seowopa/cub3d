/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_map_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:35:42 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/03 11:51:23 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player_init_status(t_map_data *_data, int _x, int _y, char face)
{
	_data->pos_x = 0;
	_data->pos_y = 0;
	_data->pos_x = (double)_x;
	_data->pos_y = (double)_y;
	_data->player_face = face;
	++(_data->num_of_player);
}

void	make_floor_rgb(t_map_data *_data)
{
	_data->floor_rgb = (_data->floor_r << 16) | \
					(_data->floor_g << 8) | \
					_data->floor_b;
	_data->ceiling_rgb = (_data->ceiling_r << 16) | \
					(_data->ceiling_g << 8) | \
					_data->ceiling_b;
}
