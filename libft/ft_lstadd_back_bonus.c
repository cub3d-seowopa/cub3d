/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:57:02 by chanwopa          #+#    #+#             */
/*   Updated: 2022/11/14 18:07:11 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr_lst;

	if (!new)
		return ;
	ptr_lst = ft_lstlast(*lst);
	if (!ptr_lst)
		*lst = new;
	else
		ptr_lst->next = new;
}
