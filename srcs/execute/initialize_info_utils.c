/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_info_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:02:00 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/03 12:12:37 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_init_directions(t_mlx_info *info, double _x, double _y)
{
	info->dirx = _x;
	info->diry = _y;
}

static void	set_init_plane(t_mlx_info *info, double _x, double _y)
{
	info->planex = _x;
	info->planey = _y;
}

int	convert_map_data(char map_elements)
{
	if (map_elements == ' ')
		return (-1);
	else if (map_elements == 'N' || map_elements == 'S' || \
			map_elements == 'E' || map_elements == 'W')
		return (0);
	else
		return (map_elements - '0');
}

void	player_start_position(t_mlx_info *info, t_map_data *data)
{
	info->posx = data->pos_x + 0.5;
	info->posy = data->pos_y + 0.5;
	if (data->player_face == 'N')
	{
		set_init_directions(info, -1.0, 0.0);
		set_init_plane(info, 0, 0.66);
	}
	else if (data->player_face == 'S')
	{
		set_init_directions(info, 1.0, 0.0);
		set_init_plane(info, 0, -0.66);
	}
	else if (data->player_face == 'W')
	{
		set_init_directions(info, 0.0, -1.0);
		set_init_plane(info, -0.66, 0);
	}
	else if (data->player_face == 'E')
	{
		set_init_directions(info, 0.0, 1.0);
		set_init_plane(info, 0.66, 0);
	}
}
