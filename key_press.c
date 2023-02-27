/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:47:02 by chanwopa          #+#    #+#             */
/*   Updated: 2023/02/27 20:50:26 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	forward_backward(t_info *info, int sign, \
							int worldMap[MAPWIDTH][MAPHEIGHT])
{
	if (worldMap[(int)(info->pos_x + info->dir_x * info->movespeed * sign)] \
				[(int)(info->pos_y)] == 0)
		info->pos_x += info->dir_x * info->movespeed * sign;
	if (worldMap[(int)(info->pos_x)] \
			[(int)(info->pos_y - info->dir_y * info->movespeed * sign)] == 0)
		info->pos_y += info->dir_y * info->movespeed * sign;
}

static void	rotate(t_info *info, int sign)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(info->rotspeed * sign) - \
					info->dir_y * sin(info->rotspeed * sign);
	info->dir_y = olddir_x * sin(info->rotspeed * sign) + \
					info->dir_y * cos(info->rotspeed * sign);
	oldplane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(info->rotspeed * sign) - \
					info->plane_y * sin(info->rotspeed * sign);
	info->plane_y = oldplane_x * sin(info->rotspeed * sign) + \
					info->plane_y * cos(info->rotspeed * sign);
}

int	key_press(int key, t_info *info, int worldMap[MAPWIDTH][MAPHEIGHT])
{
	if (key == K_W)
		forward_backward(info, 1, worldMap);
	else if (key == K_S)
		forward_backward(info, -1, worldMap);
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
