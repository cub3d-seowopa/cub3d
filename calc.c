/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:33:46 by chanwopa          #+#    #+#             */
/*   Updated: 2023/02/27 20:46:08 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_buff(t_info *info)
{
	int	i;
	int	j;

	if (info->re_buf == YES)
	{
		i = -1;
		while (++i < HEIGHT)
		{
			j = -1;
			while (++j < WIDTH)
				info->buf[i][j] = 0;
		}
	}
}

static void	init_rd_mp_dd(t_info *in, t_calc *c_in, int x)
{
	/* 벽에 부딪혔는지 여부 */
	c_in->hit = 0;
	/* camera_x : for문의 x값이 카메라평면에서 어느 위치에 있는가, x의 범위는 0~WIDTH 이므로 camera_X는 -1 ~ 1 사이값을 가짐 */
	c_in->camera_x = 2 * x / (double)WIDTH - 1;
	/* raydir_* : 현재 ray의 방향벡터 성분, 식 = 방향벡터 + 카메라벡터 * 배율 */
	c_in->raydir_x = in->dir_x + in->plane_x * c_in->camera_x;
	c_in->raydir_y = in->dir_y + in->plane_y * c_in->camera_x;
	/* map_* : 현재 ray위치, 시작은 player 위치의 정수형 */
	c_in->map_x = (int)in->pos_x;
	c_in->map_y = (int)in->pos_y;
	/* deltadist_* : x/y면에서 다음 면까지의 광선의 이동거리. deltadistX만큼 빛이 이동했다면 map_x는 1 이동한 것 */
	c_in->deltadist_x = fabs(1 / c_in->raydir_x);
	c_in->deltadist_y = fabs(1 / c_in->raydir_y);
}

static void	init_step_sd(t_info *in, t_calc *c_in)
{
	if (c_in->raydir_x < 0)
	{
		c_in->step_x = -1;
		c_in->sidedist_x = (in->pos_x - c_in->map_x) * c_in->deltadist_x;
	}
	else
	{
		c_in->step_x = 1;
		c_in->sidedist_x = (c_in->map_x + 1.0 - in->pos_x) * c_in->deltadist_x;
	}
	if (c_in->raydir_y < 0)
	{
		c_in->step_y = -1;
		c_in->sidedist_y = (in->pos_y - c_in->map_y) * c_in->deltadist_y;
	}
	else
	{
		c_in->step_y = 1;
		c_in->sidedist_y = (c_in->map_y + 1.0 - in->pos_y) * c_in->deltadist_y;
	}
}

static void	hit_wall_by_ray(t_info *in, t_calc *c_in, int worldMap[MAPWIDTH][MAPHEIGHT])
{
	while (c_in->hit == NO)
	{
		if (c_in->sidedist_x < c_in->sidedist_y)
		{
			c_in->sidedist_x += c_in->deltadist_x;
			c_in->map_x += c_in->step_x;
			c_in->side = HIT_WALLX;
		}
		else
		{
			c_in->sidedist_y += c_in->deltadist_y;
			c_in->map_y += c_in->step_y;
			c_in->side = HIT_WALLY;
		}
		if (worldMap[c_in->map_x][c_in->map_y] > 0)
			c_in->hit = YES;
	}
	if (c_in->side == HIT_WALLX)
		c_in->perpwalldist = (c_in->map_x - in->pos_x + (1 - c_in->step_x) / 2) \
								/ c_in->raydir_x;
	else
		c_in->perpwalldist = (c_in->map_y - in->pos_y + (1 - c_in->step_y) / 2) \
								/ c_in->raydir_y;
}

static void	init_draw_tex(t_info *in, t_calc *c_in, int worldMap[MAPWIDTH][MAPHEIGHT])
{
	c_in->line_height = (int)(HEIGHT / c_in->perpwalldist);
	c_in->draw_start = HEIGHT / 2 - c_in->line_height / 2;
	if (c_in->draw_start < 0)
		c_in->draw_start = 0;
	c_in->draw_end = HEIGHT / 2 + c_in->line_height / 2;
	if (c_in->draw_end >= HEIGHT)
		c_in->draw_end = HEIGHT - 1;
	c_in->tex_num = worldMap[c_in->map_x][c_in->map_y];
	if (c_in->side == HIT_WALLX)
		c_in->wall_x = in->pos_y + c_in->perpwalldist * c_in->raydir_y;
	else
		c_in->wall_x = in->pos_x + c_in->perpwalldist * c_in->raydir_x;
	c_in->wall_x -= floor(c_in->wall_x);
	c_in->tex_x = (int)(c_in->wall_x * (double)TEXWIDTH);
	if (c_in->side == HIT_WALLX && c_in->raydir_x > 0)
		c_in->tex_x = TEXWIDTH - c_in->tex_x - 1;
	if (c_in->side == HIT_WALLY && c_in->raydir_y < 0)
		c_in->tex_x = TEXWIDTH - c_in->tex_x - 1;
}

static void	draw_pixel(t_info *in, t_calc *c_in, int x)
{
	int	y;

	c_in->step = 1.0 * TEXHEIGHT / c_in->line_height;
	c_in->tex_pos = (c_in->draw_start - HEIGHT / 2 + c_in->line_height / 2) \
						* c_in->step;
	y = c_in->draw_start - 1;
	while (++y < c_in->draw_end)
	{
		c_in->tex_y = (int)c_in->tex_pos & (TEXHEIGHT - 1);
		c_in->tex_pos += c_in->step;
		c_in->color = in->texture[c_in->tex_num] \
						[TEXHEIGHT * c_in->tex_y + c_in->tex_x];
		if (c_in->side == HIT_WALLY)
			c_in->color = (c_in->color >> 1) & 8355711;
		in->buf[y][x] = c_in->color;
		in->re_buf = YES;
	}
}

void	calc(t_info *info, int worldMap[MAPWIDTH][MAPHEIGHT])
{
	int		x;
	t_calc	c_info;

	init_buff(info);
	x = -1;
	while (++x < WIDTH)
	{
		init_rd_mp_dd(info, &c_info, x);
		init_step_sd(info, &c_info);
		hit_wall_by_ray(info, &c_info, worldMap);
		init_draw_tex(info, &c_info, worldMap);
		draw_pixel(info, &c_info, x);
	}
}
