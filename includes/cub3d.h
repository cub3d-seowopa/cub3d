/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:03:41 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/27 18:20:39 by seowokim         ###   ########seoul.kr  */
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

# define RED "\33[31m"
# define WHITE "\33[37m"
# define BUFFER_SIZE 5

	/*    get_next_line   */
char		*get_next_line(int fd);
char		*make_temp(void);
char		*memory_set(int index, int ckt);

int			print_error_msg(char *message, int _errno);
void		free_all_memory(t_mlx_info *_info, t_map_data *_data);


/************************************************/
/*					parsing						*/
/************************************************/
	/* initialize_data.c */
int			init(t_map_data **_data, char *av);
	/* set_data_map.c */
int			read_map_file(t_map_data *_data, const char *path);
int			put_map_data(char *str, t_map_data *_data);
char		*check_identifier(char *str, int *value_start_index);
	/* set_data_map_utils.c */
char		*get_texture_path(t_map_data *_data, char *str,
				int path_start_index);
int			get_floor_rgb(t_map_data *_data, char *str, int rgb_start_index);
int			get_ceiling_rgb(t_map_data	*_data, char *str, int rgb_start_index);
int			check_data_is_full(t_map_data *_data);
	/* validate_map_data.c */
int			check_map_data_vaildation(t_map_data *_data, int fd);
	/* validate_map_data_utils.c */
int			check_all_neighbor(t_map_data *_data);
int			is_boundary_wall(char *map_line, int index, int max_line);
	/* parsing_utils.c */
int			ft_my_strstr(char *str1, char *str2);
int			check_rgb(int rgb);
int			free_strings(char *str1, char *str2, int return_value);
void		print_map_data(t_map_data *_data);
int			ft_free_double_string(char **str, int ret);

#endif /* CUB3D_H */