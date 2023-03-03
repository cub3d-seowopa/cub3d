/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:03:30 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/03 15:28:42 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_loop(t_mlx_info *info)
{
	calc(info);
	draw(info);
	key_update(info);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx_info	mlx_info;
	t_map_data	*map_data;

	map_data = NULL;
	if (argc != 2)
		return (print_error_msg("Check number of inputs", -1));
	if (!init_map_data(&map_data, argv[1]))
		return (-1);
	if (read_map_file(map_data, argv[1]) <= 0)
		return (free_map_data(map_data));
	copy_data_to_info(&mlx_info, map_data);
	init_mlx_info(&mlx_info, map_data);
	init_malloc(&mlx_info, map_data);
	free_map_data(map_data);
	mlx_loop_hook(mlx_info.mlx, &main_loop, &mlx_info);
	mlx_hook(mlx_info.win, X_EVENT_KEY_PRESS, 0, &key_press, &mlx_info);
	mlx_hook(mlx_info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &mlx_info);
	mlx_hook(mlx_info.win, 17, 0, &close_window, &mlx_info);
	mlx_loop(mlx_info.mlx);
	return (0);
}
