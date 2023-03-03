/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:03:41 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/03 15:27:44 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_info.h"
# include "map_data.h"
# include "key_macos.h"
# include "my_define.h"

	/*    get_next_line   */
char		*get_next_line(int fd);
char		*make_temp(void);
char		*memory_set(int index, int ckt);

	/* error_handling */
int			close_window(t_mlx_info *info);
int			print_error_msg(char *message, int _errno);
int			free_map_data(t_map_data *_data);

/************************************************/
/*					parsing						*/
/************************************************/
	/* initialize_data.c */
int			init_map_data(t_map_data **_data, char *av);
	/* set_data_map.c */
int			read_map_file(t_map_data *_data, const char *map_path);
	/* set_data_map_utils.c */
char		*get_texture_path(t_map_data *_data, char *str,
				int path_start_index);
int			get_floor_rgb(t_map_data *_data, char *str, int rgb_start_index);
int			get_ceiling_rgb(t_map_data	*_data, char *str, int rgb_start_index);
int			check_data_is_full(t_map_data *_data);
	/* set_data_map_utils2.c */
void		put_player_init_status(t_map_data *_data, int _x, int _y, \
									char face);
void		make_floor_rgb(t_map_data *_data);
	/* validate_map_data.c */
int			check_map_data_vaildation(t_map_data *_data, int fd);
	/* validate_map_data_utils.c */
int			check_map(t_map_data *_data);
int			check_path_is_valided(t_map_data *_data);
	/* parsing_utils.c */
int			ft_my_strstr(char *str1, char *str2);
int			check_rgb(int rgb);
int			free_strings(char *str1, char *str2, int return_value);
int			ft_free_double_string(char **str, int ret);
void		print_map_data(t_map_data *_data);

/************************************************/
/*					execute						*/
/************************************************/
	/* initailize_info.c */
void		init_mlx_info(t_mlx_info *info, t_map_data *data);
void		copy_data_to_info(t_mlx_info *_info, t_map_data *_data);
void		init_malloc(t_mlx_info *info, t_map_data *data);
	/* initailize_info_utils.c */
int			convert_map_data(char map_elements);
void		player_start_position(t_mlx_info *info, t_map_data *data);
	/* calc.c */
void		calc(t_mlx_info *info);
	/* key.c */
int			key_press(int key, t_mlx_info *info);
int			key_release(int key, t_mlx_info *info);
int			key_update(t_mlx_info *info);
	/* key_event.c */
void		updown(t_mlx_info *info, int sign);
void		leftright(t_mlx_info *info, int sign);
void		rotate(t_mlx_info *info, int sign);
	/* render.c */
void		load_texture(t_mlx_info *info, t_map_data *data);
void		load_image(t_mlx_info *info, int *texture, char *path, t_img *img);
void		draw(t_mlx_info *info);

#endif /* CUB3D_H */