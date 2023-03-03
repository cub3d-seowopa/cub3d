/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:26:29 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/03 15:31:00 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	updown(t_mlx_info *info, int sign)
{
	if (!info->world_map[(int)(info->posx + info->dirx * \
		info->movespeed * sign)][(int)(info->posy)])
		info->posx += info->dirx * info->movespeed * sign;
	if (!info->world_map[(int)(info->posx)][(int)(info->posy \
			+ info->diry * info->movespeed * sign)])
		info->posy += info->diry * info->movespeed * sign;
}

void	leftright(t_mlx_info *info, int sign)
{
	if (!info->world_map[(int)(info->posx + info->planex * \
		info->movespeed * sign)][(int)(info->posy)])
		info->posx += info->planex * info->movespeed * sign;
	if (!info->world_map[(int)(info->posx)][(int)(info->posy \
			+ info->planey * info->movespeed * sign)])
		info->posy += info->planey * info->movespeed * sign;
}

void	rotate(t_mlx_info *info, int sign)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->dirx;
	oldplane_x = info->planex;
	info->dirx = info->dirx * cos(info->rotspeed * sign) - \
				info->diry * sin(info->rotspeed * sign);
	info->diry = olddir_x * sin(info->rotspeed * sign) + \
				info->diry * cos(info->rotspeed * sign);
	info->planex = info->planex * cos(info->rotspeed * sign) - \
					info->planey * sin(info->rotspeed * sign);
	info->planey = oldplane_x * sin(info->rotspeed * sign) + \
					info->planey * cos(info->rotspeed * sign);
}
