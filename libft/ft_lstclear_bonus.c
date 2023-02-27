/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:08:21 by chanwopa          #+#    #+#             */
/*   Updated: 2022/11/14 18:07:18 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*ptr_next;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		ptr_next = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = ptr_next;
	}
	*lst = NULL;
}
