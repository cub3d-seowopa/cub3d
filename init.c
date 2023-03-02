/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:16:47 by chanwopa          #+#    #+#             */
/*   Updated: 2023/03/01 20:19:05 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_info(t_info *info)
{
	info->mlx = mlx_init();
	info->posx = 22.0;
	info->posy = 11.5;
	info->dirx = -1.0;
	info->diry = 0.0;
	info->planex = 0.0;
	info->planey = 0.66;
	info->re_buf = 0;
	info->movespeed = 0.05;
	info->rotspeed = 0.05;
	info->win = mlx_new_window(info->mlx, width, height, "mlx");
	info->img.img = mlx_new_image(info->mlx, width, height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, \
									&info->img.size_l, &info->img.endian);
	info->texture = malloc(sizeof(int *) * 8);
	if (!info->texture)
		exit(1);
	info->key.key_w = 0;
	info->key.key_a = 0;
	info->key.key_s = 0;
	info->key.key_d = 0;
}

void	init_malloc(t_info *info)
{
	int	i;

	i = -1;
	while (++i < height)
		ft_memset(info->buf[i], 0, sizeof(int) * width);
	i = -1;
	while (++i < 8)
	{
		info->texture[i] = malloc(sizeof(int) * (texHeight * texWidth));
		if (!info->texture[i])
			exit(1);
	}
	i = -1;
	while (++i < 8)
		ft_memset(info->texture[i], 0, sizeof(int) * texHeight * texWidth);
	load_texture(info);
}

void	copy_worldmap(t_info *info, int worldMap[mapWidth][mapHeight])
{
	int	i;
	int	j;

	info->world_map = malloc(sizeof(int *) * mapHeight);
	if (!info->world_map)
		exit(1);
	i = -1;
	while (++i < mapHeight)
	{
		info->world_map[i] = malloc(sizeof(int) * mapWidth);
		if (!info->world_map[i])
			exit(1);
	}
	i = -1;
	while (++i < mapHeight)
	{
		j = -1;
		while (++j < mapWidth)
			info->world_map[i][j] = worldMap[i][j];
	}
}