/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:13:07 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/12 08:42:34 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"
#include "ft_printf.h"
#include "libft.h"

//Hacer inverso
void	order3only(t_stack *st, t_list *l, char sel, int inv)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = ((- (st->total - 1)) * inv + (int)((t_num *)(l->content))->order);
	n2 = (((- st->total - 1)) * inv + (int)((t_num *)(l->next)->content)->order);
	if (l->next->next)
		n3 = (int)((t_num *)(l->next->next)->content)->order;
	else if (n1 > n2 && !(l->next->next))
		sab(st, sel);
	if (n1 > n2 && n1 < n3 && n2 < n3 && l->next->next)
		sab(st, sel);
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		rrab(st, sel);
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		rab(st, sel);
	else if (n2 > n3)
	{
		sab(st, sel);
		if (n1 > n2 && n1 > n3)
			rrab(st, sel);
		if (n1 < n2 && n1 < n3)
			rab(st, sel);
	}
}


void	uporder(t_stack *st, t_list *l, int order, char sel)
{
	t_list	*lst;
	int		cnt;
	int		size;

	size = st->na;
	cnt = 0;
	lst = l;
	while (((t_num *)(lst->content))->order != order)
	{
		lst = lst->next;
		cnt++;
	}
	if (cnt <= (size / 2))
		while (cnt--)
			rab(st, sel);
	else
	{
		cnt = size - cnt;
		while (cnt--)
			rrab(st, sel);
	}
}

void	order5only(t_stack *st)
{
	if (!st->a->next)
		return ;
	if (!st->a->next->next || !st->a->next->next->next)
	{
		order3only(st, st->a, A, 0);
		return ;
	}
	if (st->a->next->next->next->next == 0)
	{
		uporder(st, st->a, 0, A);
		pb(st);
		order3only(st, st->a, A, 0);
		pa(st);
	}
	else
	{
		uporder(st, st->a, 0, A);
		pb(st);
		uporder(st, st->a, 1, A);
		pb(st);
		order3only(st, st->a, A, 0);
		pa(st);
		pa(st);
	}
}

int	push_swap(t_stack *st)
{
	//order3only(st, st->a, A, 0);
	order5only(st);
	print_instr(st);
	print_status(*st);
	//exec_instr(st, PRINT);
	return (0);
}
