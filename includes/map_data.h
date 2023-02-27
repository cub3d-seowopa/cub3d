/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:03:36 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/26 20:08:29 by seowoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DATA_H
# define MAP_DATA_H

typedef struct s_map_data{
	char	*north_tex_path;
	char	*south_tex_path;
	char	*west_tex_path;
	char	*east_tex_path;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	char	**map;
	int		num_of_data_except_map;
	int		num_of_map_line;
}	t_map_data;

#endif /* MAP_DATA_H */