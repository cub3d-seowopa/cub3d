/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:19:11 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/02 21:07:12 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_data_vaildation(t_map_data *_data, int fd)
{
	close (fd);
	if (!(check_rgb(_data->ceiling_r) && check_rgb(_data->ceiling_g) \
		&& check_rgb(_data->ceiling_b) && check_rgb(_data->floor_r) \
		&& check_rgb(_data->floor_g) && check_rgb(_data->floor_b)))
		return (print_error_msg("RGB is out of range", 0));
	else if (ft_strncmp(_data->north_tex_path, "\0", 1) == 0 || \
			ft_strncmp(_data->south_tex_path, "\0", 1) == 0 || \
			ft_strncmp(_data->west_tex_path, "\0", 1) == 0 || \
			ft_strncmp(_data->east_tex_path, "\0", 1) == 0)
		return (print_error_msg("There is empty texture path", 0));
	else if (!check_path_is_valided(_data))
		return (print_error_msg("Invaild texture path", 0));
	else if (!check_map(_data))
		return (print_error_msg("Invaild map", 0));
	make_floor_rgb(_data);
	return (1);
}
