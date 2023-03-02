/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:39:59 by chanwopa          #+#    #+#             */
/*   Updated: 2023/03/02 17:01:50 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	updown(t_mlx_info *info, int sign)
{
	if (!info->world_map[(int)(info->posx + info->dirx * \
		info->movespeed * sign)][(int)(info->posy)])
		info->posx += info->dirx * info->movespeed * sign;
	if (!info->world_map[(int)(info->posx)][(int)(info->posy \
			+ info->diry * info->movespeed * sign)])
		info->posy += info->diry * info->movespeed * sign;
}

static void	rotate(t_mlx_info *info, int sign)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->dirx;
	info->dirx = info->dirx * cos(info->rotspeed * sign) - \
				info->diry * sin(info->rotspeed * sign);
	info->diry = olddir_x * sin(info->rotspeed * sign) + \
				info->diry * cos(info->rotspeed * sign);
	oldplane_x = info->planex;
	info->planex = info->planex * cos(info->rotspeed * sign) - \
					info->planey * sin(info->rotspeed * sign);
	info->planey = oldplane_x * sin(info->rotspeed * sign) + \
					info->planey * cos(info->rotspeed * sign);
}

int	key_update(t_mlx_info *info)
{
	if (info->key.key_w == 1)
		updown(info, 1);
	if (info->key.key_s == 1)
		updown(info, -1);
	if (info->key.key_left_arrow == 1)
		rotate(info, 1);
	if (info->key.key_right_arrow == 1)
		rotate(info, -1);
	return (0);
}

int	key_press(int key, t_mlx_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key.key_w = 1;
	else if (key == K_A)
		info->key.key_a = 1;
	else if (key == K_S)
		info->key.key_s = 1;
	else if (key == K_D)
		info->key.key_d = 1;
	else if (key == K_AR_L)
		info->key.key_left_arrow = 1;
	else if (key == K_AR_R)
		info->key.key_right_arrow = 1;
	return (0);
}

int	key_release(int key, t_mlx_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key.key_w = 0;
	else if (key == K_A)
		info->key.key_a = 0;
	else if (key == K_S)
		info->key.key_s = 0;
	else if (key == K_D)
		info->key.key_d = 0;
	else if (key == K_AR_L)
		info->key.key_left_arrow = 0;
	else if (key == K_AR_R)
		info->key.key_right_arrow = 0;
	return (0);
}
