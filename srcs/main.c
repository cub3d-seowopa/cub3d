/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:03:30 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/26 22:26:56 by seowoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leakcheck(void)
{
	system("leaks --list cub3d");
}

int	close_window(void)
{
	exit(1);
}

int	main(int argc, char *argv[])
{
	//atexit(leakcheck);
	t_mlx_info	*mlx_info;
	t_map_data	*map_data;

	map_data = NULL;
	mlx_info = NULL;
	if (argc != 2)
		return (print_error_msg("Wrong Input", -1));
	if (!init(&map_data, argv[1]))
		return (-1);
	if (!read_map_file(map_data, argv[1]))
	{
		free_all_memory(mlx_info, map_data);
		return (-1);
	}
	free_all_memory(mlx_info, map_data);
	//mlx_pixel_put(mlx_info->mlx_ptr, mlx_info->win_ptr, 100, 100, 100);
	//mlx_hook(mlx_info->win_ptr, 17, 0, &close_window, mlx_info);
	//mlx_loop(mlx_info->mlx_ptr);
	return (0);
}
