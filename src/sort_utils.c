/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:50:14 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/26 18:54:10 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "push_swap.h"

void	uporder(t_stack *st, t_list *sel, t_list *other, int order)
{
	t_list	*lst;
	int		cnt;
	int		size;

	size = st->na;
	cnt = 0;
	lst = sel;
	while (((t_num *)(lst->content))->order != order)
	{
		lst = lst->next;
		cnt++;
	}
	if (cnt <= (size / 2))
	{
		while (cnt--)
			rab(st, &sel, &other);
	}
	else
	{
		cnt = size - cnt;
		while (cnt--)
			rrab(st, &sel, &other);
	}
}

int	smaller_order(t_list *l)
{
	int		min;

	min = 0xFFFFFF;
	while (l)
	{
		if (((t_num *)(l->content))->order < min)
			min = ((t_num *)(l->content))->order;
		l = l->next;
	}
	return (min);
}
