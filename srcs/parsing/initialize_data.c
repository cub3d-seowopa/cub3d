/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:43:48 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/02 14:38:22 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_elements_init(t_map_data *_data)
{
	_data->ceiling_b = -1;
	_data->ceiling_g = -1;
	_data->ceiling_r = -1;
	_data->floor_b = -1;
	_data->floor_g = -1;
	_data->floor_r = -1;
	_data->north_tex_path = NULL;
	_data->south_tex_path = NULL;
	_data->west_tex_path = NULL;
	_data->east_tex_path = NULL;
	_data->map = NULL;
	_data->num_of_data_except_map = 0;
	_data->num_of_map_line = 0;
	_data->bool_floor = 0;
	_data->bool_ceiling = 0;
	_data->floor_rgb = 0;
	_data->ceiling_rgb = 0;
}

// static t_mlx_info	*mlx_info_init(t_mlx_info *_info)
// {
// 	_info = (t_mlx_info *)malloc(sizeof(t_mlx_info));
// 	if (!_info)
// 		return (NULL);
// 	_info->mlx_ptr = mlx_init();
// 	_info->win_ptr = mlx_new_window(_info->mlx_ptr, 500, 400, "cub3d");
// 	return (_info);
// }

static t_map_data	*allocate_map_data(t_map_data *_data)
{
	_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (!_data)
		return (NULL);
	return (_data);
}

int	init_map_data(t_map_data **_data, char *av)
{
	if (!ft_my_strstr(av, ".cub\0"))
		return (print_error_msg("Check map file\'s type", 0));
	// *_info = mlx_info_init(*_info);
	*_data = allocate_map_data(*_data);
	if (!*_data)
		return (print_error_msg("Failed to allocate memory", 0));
	map_elements_init(*_data);
	return (1);
}
