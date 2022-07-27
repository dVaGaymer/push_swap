/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:20:07 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/27 22:06:40 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(void*))
{
	t_list	*prev;

	(*lst)->prev->next = (*lst)->next;
	prev = (*lst)->prev;
	if (del)
		(del)((*lst)->content);
	free(*lst);
	*lst = prev;
}
