/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:56:49 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/12 06:06:39 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "instructions.h"

t_list	*_p(t_list **src, t_list **dest)
{
	t_list	*second;

	second = (*src)->next;
	ft_lstadd_front(dest, *src);
	return (second);
}

void	pa(t_stack *stacks)
{
	if (stacks->nb == 0)
		return ;
	stacks->b = _p(&(stacks->b), &(stacks->a));
	stacks->nb--;
	stacks->na++;
	ft_lstadd_back(&(stacks->i), ft_lstnew(pa));
}

void	pb(t_stack *stacks)
{
	if (stacks->na == 0)
		return ;
	stacks->a = _p(&(stacks->a), &(stacks->b));
	stacks->nb++;
	stacks->na--;
	ft_lstadd_back(&(stacks->i), ft_lstnew(pb));
}

void	pab(t_stack *stacks, char sel)
{
	if (sel == A)
		pa(stacks);
	else
		pb(stacks);
}
