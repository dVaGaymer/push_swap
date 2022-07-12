/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:46:58 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/12 06:06:54 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "instructions.h"

void	_rr(t_list **l)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;
	t_list	*prelast;

	first = (*l);
	second = (*l)->next;
	last = ft_lstlast(*l);
	prelast = ft_lstprelast(*l);
	prelast->next = NULL;
	last->next = first;
	*l = last;
}

void	rra(t_stack *stacks)
{
	_rr(&(stacks->a));
	ft_lstadd_back(&(stacks->i), ft_lstnew(rra));
}

void	rrb(t_stack *stacks)
{
	_rr(&(stacks->b));
	ft_lstadd_back(&(stacks->i), ft_lstnew(rrb));
}

void	rrr(t_stack *stacks)
{
	_rr(&(stacks->a));
	_rr(&(stacks->b));
}

void	rrab(t_stack *stacks, char sel)
{
	if (sel == A)
		rra(stacks);
	else
		rrb(stacks);
}
