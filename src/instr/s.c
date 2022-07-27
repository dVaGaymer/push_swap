/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                          |*---------------------*|   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:35:23 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/27 02:40:20 by alopez-g     +-----------------------+   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include "instructions.h"

void	_s(t_list **l)
{
	t_list	*d1;
	t_list	*d2;
	t_list	*d3;

	d1 = (*l);
	d2 = (*l)->next;
	d3 = (*l)->next->next;
	d1->next = d3;
	d2->next = d1;
	*l = d2;
}

void	sa(t_stack *stacks)
{
	_s(&(stacks->a));
	ft_lstadd_back(&(stacks->i), ft_lstnew(sa));
}

void	sb(t_stack *stacks)
{
	_s(&(stacks->b));
	ft_lstadd_back(&(stacks->i), ft_lstnew(sb));
}

void	ss(t_stack *stacks)
{
	_s(&(stacks->a));
	_s(&(stacks->b));
}

void	sab(t_stack *stacks, t_list **sel, t_list **other)
{
	if (*sel == stacks->a)
	{
		sa(stacks);
		*sel = stacks->a;
		*other = stacks->b;
	}
	else
	{
		sb(stacks);
		*sel = stacks->b;
		*other = stacks->a;
	}
}
