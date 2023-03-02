/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:12:19 by chanwopa          #+#    #+#             */
/*   Updated: 2023/03/01 20:16:54 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "key_macos.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define texWidth 64
# define texHeight 64
# define mapWidth 24
# define mapHeight 24
# define width 640
# define height 480

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_key
{
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
}				t_key;


typedef struct s_info
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[height][width];
	int		**texture;
	double	movespeed;
	double	rotspeed;
	int		re_buf;
	int		**world_map;
	t_key	key;
}				t_info;

typedef struct s_calc
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	double	wallx;
	int		texx;
	double	step;
	double	texpos;
	int		texy;
	int		color;
}				t_calc;

/* functions */
int			main_loop(t_info *info);

/* init.c */
void		init_info(t_info *info);
void		init_malloc(t_info *info);
void		copy_worldmap(t_info *info, int worldMap[mapHeight][mapWidth]);

/* render.c */
void		load_texture(t_info *info);
void		load_image(t_info *info, int *texture, char *path, t_img *img);
void		draw(t_info *info);

/* key.c */
int			key_update(t_info *info);
int			key_press(int key, t_info *info);
int			key_release(int key, t_info *info);

/* calc.c */
void		calc(t_info *info);

#endif