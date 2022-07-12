/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:56:37 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/12 06:02:19 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include "instructions.h"

void	_r(t_list **l)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = (*l);
	second = (*l)->next;
	last = ft_lstlast(*l);
	first->next = NULL;
	last->next = first;
	*l = second;
}

void	ra(t_stack *stacks)
{
	_r(&(stacks->a));
	ft_lstadd_back(&(stacks->i), ft_lstnew(ra));
}

void	rb(t_stack *stacks)
{
	_r(&(stacks->b));
	ft_lstadd_back(&(stacks->i), ft_lstnew(rb));
}

void	rr(t_stack *stacks)
{
	_r(&(stacks->a));
	_r(&(stacks->b));
}

void	rab(t_stack *stacks, char	sel)
{
	if (sel == A)
		ra(stacks);
	else
		rb(stacks);
}
