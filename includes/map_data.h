/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:03:36 by seowokim          #+#    #+#             */
/*   Updated: 2023/03/02 18:17:33 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DATA_H
# define MAP_DATA_H

typedef struct s_map_data{
	char			*north_tex_path;
	char			*south_tex_path;
	char			*west_tex_path;
	char			*east_tex_path;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				bool_floor;
	int				ceiling_r;
	int				ceiling_g;
	int				ceiling_b;
	unsigned int	ceiling_rgb;
	unsigned int	floor_rgb;
	int				bool_ceiling;
	char			**map;
	int				num_of_data_except_map;
	int				num_of_map_line;
	double			pos_x;
	double			pos_y;
	char			player_face;
	int				num_of_player;
}	t_map_data;

#endif /* MAP_DATA_H */