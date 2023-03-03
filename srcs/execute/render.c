/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:36:20 by chanwopa          #+#    #+#             */
/*   Updated: 2023/03/03 15:24:41 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_mlx_info *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
			info->img.data[y * WINDOW_WIDTH + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	load_image(t_mlx_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(info->mlx, path, \
								&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, \
								&img->bpp, &img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_mlx_info *info, t_map_data *data)
{
	t_img	img;

	load_image(info, info->texture[0], data->east_tex_path, &img);
	load_image(info, info->texture[1], data->west_tex_path, &img);
	load_image(info, info->texture[2], data->south_tex_path, &img);
	load_image(info, info->texture[3], data->north_tex_path, &img);
	info->texture[4] = NULL;
}
