/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:39:59 by chanwopa          #+#    #+#             */
/*   Updated: 2023/03/01 17:36:35 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	updown(t_info *info, int sign)
{
	if (!info->world_map[(int)(info->posx + info->dirx * \
		info->movespeed * sign)][(int)(info->posy)])
		info->posx += info->dirx * info->movespeed * sign;
	if (!info->world_map[(int)(info->posx)][(int)(info->posy \
			+ info->diry * info->movespeed * sign)])
		info->posy += info->diry * info->movespeed * sign;
}

static void	rotate(t_info *info, int sign)
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

int	key_press(int key, t_info *info)
{
	if (key == K_W)
		updown(info, 1);
	else if (key == K_S)
		updown(info, -1);
	else if (key == K_D)
		rotate(info, -1);
	else if (key == K_A)
		rotate(info, 1);
	else if (key == K_ESC)
		exit(0);
	mlx_clear_window(info->mlx, info->win);
	main_loop(info);
	return (0);
}