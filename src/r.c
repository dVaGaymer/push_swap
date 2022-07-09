/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:56:37 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/08 23:53:56 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	_r(t_list **l)
{
	t_list	*first, *second, *last;
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
}

void	rb(t_stack *stacks)
{
	_r(&(stacks->b));
}

void	rr(t_stack *stacks)
{
	_r(&(stacks->a));
	_r(&(stacks->b));
}
