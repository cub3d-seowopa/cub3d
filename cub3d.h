/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:22:20 by chanwopa          #+#    #+#             */
/*   Updated: 2023/02/27 21:00:13 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "key_macos.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define TEXWIDTH			64
# define TEXHEIGHT			64

# define MAPWIDTH			24
# define MAPHEIGHT			24

# define WIDTH				640
# define HEIGHT				480

# define YES 				1
# define NO 				0

# define HIT_WALLX			0
# define HIT_WALLY			1

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

typedef struct s_info
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	void	*mlx;
	void	*win;
	t_img	img;
	int		**buf;
	int		**texture;
	double	movespeed;
	double	rotspeed;
	int		re_buf;

}				t_info;

typedef struct s_calc
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	int		tex_x;
	int		tex_y;
	int		color;

	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	double	wall_x;
	double	step;
	double	tex_pos;
}				t_calc;

void	calc(t_info *info, int worldMap[MAPWIDTH][MAPHEIGHT]);
int		key_press(int key, t_info *info, int worldMap[MAPWIDTH][MAPHEIGHT]);

int		main_loop(t_info *info);

void	load_texture(t_info *info);
void	load_image(t_info *info, int *texture, char *path, t_img *img);

#endif