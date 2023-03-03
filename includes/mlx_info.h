/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:11:53 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/03 15:18:12 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INFO_H
# define MLX_INFO_H

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 480

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
	int		key_left_arrow;
	int		key_right_arrow;
}				t_key;

typedef struct s_mlx_info
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	void			*mlx;
	void			*win;
	t_img			img;
	int				buf[WINDOW_HEIGHT][WINDOW_WIDTH];
	int				**texture;
	unsigned int	floor_rgb;
	unsigned int	ceiling_rgb;
	double			movespeed;
	double			rotspeed;
	int				re_buf;
	int				**world_map;
	t_key			key;
}				t_mlx_info;

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

#endif /* MLX_INFO_H */