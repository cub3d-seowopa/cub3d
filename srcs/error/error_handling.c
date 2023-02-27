/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:26:43 by seowokim          #+#    #+#             */
/*   Updated: 2023/02/24 16:59:44 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error_msg(char *message, int _errno)
{
	ft_putstr_fd("Error\n----> ", 2);
	ft_putstr_fd(RED, 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd(WHITE, 2);
	return (_errno);
}
