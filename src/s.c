/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:35:23 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/08 23:29:05 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	s(t_list **l)
{
	t_list *d1, *d2, *d3;

	d1 = (*l);
	d2 = (*l)->next;
	d3 = (*l)->next->next;
	d1->next = d3;
	d2->next = d1;
	*l = d2;
}

void	sa(t_stack *stacks)
{
	s(&(stacks->a));
}

void	sb(t_stack *stacks)
{
	s(&(stacks->b));
}

void	ss(t_stack *stacks)
{
	s(&(stacks->a));
	s(&(stacks->b));
}
