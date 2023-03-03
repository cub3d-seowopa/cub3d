/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:39:59 by chanwopa          #+#    #+#             */
/*   Updated: 2023/03/03 15:26:55 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_update(t_mlx_info *info)
{
	if (info->key.key_w == 1)
		updown(info, 1);
	if (info->key.key_s == 1)
		updown(info, -1);
	if (info->key.key_a == 1)
		leftright(info, -1);
	if (info->key.key_d == 1)
		leftright(info, 1);
	if (info->key.key_left_arrow == 1)
		rotate(info, 1);
	if (info->key.key_right_arrow == 1)
		rotate(info, -1);
	return (0);
}

int	key_press(int key, t_mlx_info *info)
{
	if (key == K_ESC)
		close_window(info);
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
