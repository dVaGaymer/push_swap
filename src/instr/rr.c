/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:46:58 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/09 20:50:57 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
}
void	rrb(t_stack *stacks)
{
	_rr(&(stacks->b));
}
void	rrr(t_stack *stacks)
{
	_rr(&(stacks->a));
	_rr(&(stacks->b));
}
