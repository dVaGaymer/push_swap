/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:56:49 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/08 23:29:44 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list*	_p(t_list **src, t_list **dest)
{
	t_list	*second;

	second = (*src)->next;
	ft_lstadd_front(dest, *src);
	return (second);
}

void	pa(t_stack *stacks)
{
	stacks->a = _p(&(stacks->a), &(stacks->b));
	stacks->na--;
	stacks->nb++;
}

void	pb(t_stack *stacks)
{
	stacks->b = _p(&(stacks->b), &(stacks->a));
	stacks->na++;
	stacks->nb--;
}
