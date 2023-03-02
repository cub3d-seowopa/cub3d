/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:35:14 by chanwopa          #+#    #+#             */
/*   Updated: 2023/03/02 16:03:14 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

void	calc_first(t_info *in, t_calc *c_in)
{
	c_in->mapx = (int)in->posx;
	c_in->mapy = (int)in->posy;
	c_in->deltadistx = fabs(1 / c_in->raydirx);
	c_in->deltadisty = fabs(1 / c_in->raydiry);
	c_in->hit = 0;
	if (c_in->raydirx < 0)
	{
		c_in->stepx = -1;
		c_in->sidedistx = (in->posx - c_in->mapx) * c_in->deltadistx;
	}
	else
	{
		c_in->stepx = 1;
		c_in->sidedistx = (c_in->mapx + 1.0 - in->posx) * c_in->deltadistx;
	}
	if (c_in->raydiry < 0)
	{
		c_in->stepy = -1;
		c_in->sidedisty = (in->posy - c_in->mapy) * c_in->deltadisty;
	}
	else
	{
		c_in->stepy = 1;
		c_in->sidedisty = (c_in->mapy + 1.0 - in->posy) * c_in->deltadisty;
	}
}

void	move_ray_until_hit(t_info *in, t_calc *c_in)
{
	while (c_in->hit == 0)
	{
		if (c_in->sidedistx < c_in->sidedisty)
		{
			c_in->sidedistx += c_in->deltadistx;
			c_in->mapx += c_in->stepx;
			c_in->side = 0;
		}
		else
		{
			c_in->sidedisty += c_in->deltadisty;
			c_in->mapy += c_in->stepy;
			c_in->side = 1;
		}
		if (in->world_map[c_in->mapx][c_in->mapy] > 0)
			c_in->hit = 1;
	}
}

void	calc_second(t_info *in, t_calc *c_in)
{
	if (c_in->side == 0)
		c_in->perpwalldist = \
			(c_in->mapx - in->posx + (1 - c_in->stepx) / 2) / c_in->raydirx;
	else
		c_in->perpwalldist = \
			(c_in->mapy - in->posy + (1 - c_in->stepy) / 2) / c_in->raydiry;
	c_in->lineheight = (int)(height / c_in->perpwalldist);
	c_in->drawstart = -c_in->lineheight / 2 + height / 2;
	if (c_in->drawstart < 0)
		c_in->drawstart = 0;
	c_in->drawend = c_in->lineheight / 2 + height / 2;
	if (c_in->drawend >= height)
		c_in->drawend = height - 1;

	// set texture number. modified based on wall direction */
	if (c_in->side == 0 && c_in->raydirx > 0)
		c_in->texnum = 1;
	else if (c_in->side == 0 && c_in->raydirx < 0)
		c_in->texnum = 2;
	if (c_in->side == 1 && c_in->raydiry > 0)
		c_in->texnum = 3;
	else if (c_in->side == 1 && c_in->raydiry < 0)
		c_in->texnum = 4;

	if (c_in->side == 0)
		c_in->wallx = in->posy + c_in->perpwalldist * c_in->raydiry;
	else
		c_in->wallx = in->posx + c_in->perpwalldist * c_in->raydirx;
	c_in->wallx -= floor(c_in->wallx);
}

void	calc_third(t_info *in, t_calc *c_in, int x)
{
	int	y;

	c_in->texx = (int)(c_in->wallx * (double)texWidth);
	/* 텍스쳐 대칭 보정 */
	if (c_in->side == 0 && c_in->raydirx > 0)
		c_in->texx = texWidth - c_in->texx - 1;
	if (c_in->side == 1 && c_in->raydiry < 0)
		c_in->texx = texWidth - c_in->texx - 1;

	c_in->step = 1.0 * texHeight / c_in->lineheight;
	c_in->texpos = (c_in->drawstart - height / 2 \
					+ c_in->lineheight / 2) * c_in->step;
	y = c_in->drawstart - 1;
	while (++y < c_in->drawend)
	{
		/* 유일하게 이해 안가는 부분. 오버플로우 방지? */
		c_in->texy = (int)c_in->texpos & (texHeight - 1);
		c_in->texpos += c_in->step;
		c_in->color = \
			in->texture[c_in->texnum][texHeight * c_in->texy + c_in->texx];
		in->buf[y][x] = c_in->color;
		in->re_buf = 1;
	}
}

void	calc(t_info *info)
{
	int		x;
	t_calc	c_info;

	if (info->re_buf == 1)
	{
		x = -1;
		while (++x < height)
			ft_memset(info->buf[x], 0, sizeof(int) * width);
	}
	x = -1;
	while (++x < width)
	{
		c_info.camerax = 2 * x / (double)width - 1;
		c_info.raydirx = info->dirx + info->planex * c_info.camerax;
		c_info.raydiry = info->diry + info->planey * c_info.camerax;
		calc_first(info, &c_info);
		move_ray_until_hit(info, &c_info);
		calc_second(info, &c_info);
		calc_third(info, &c_info, x);
	}
}