/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:13:07 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/26 23:51:59 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bitwise.h"
#include "instructions.h"
#include "ft_printf.h"
#include "libft.h"

void	order3only(t_stack *st)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (int)((t_num *)(st->a->content))->order;
	n2 = (int)((t_num *)(st->a->next)->content)->order;
	if (n1 > n2 && !(st->a->next->next))
		return (sa(st));
	if (n1 < n2 && !(st->a->next->next))
		return ;
	n3 = (int)((t_num *)(st->a->next->next)->content)->order;
	if (n1 > n2 && n1 < n3 && n2 < n3 && st->a->next->next)
		sa(st);
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		rra(st);
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		ra(st);
	else if (n2 > n3)
	{
		sa(st);
		if (n1 > n2 && n1 > n3)
			rra(st);
		if (n1 < n2 && n1 < n3)
			ra(st);
	}
}

void	order5only(t_stack *st)
{
	if (!st->a->next)
		return ;
	if (!st->a->next->next || !st->a->next->next->next)
		return (order3only(st));
	if (st->a->next->next->next->next == 0)
	{
		uporder(st, st->a, st->b, smaller_order(st->a));
		pb(st);
		order3only(st);
		pa(st);
	}
	else
	{
		uporder(st, st->a, st->b, smaller_order(st->a));
		pb(st);
		uporder(st, st->a, st->b, smaller_order(st->a));
		pb(st);
		order3only(st);
		pa(st);
		pa(st);
	}
}

/*
 * Mueve de un stack a otro todos los numeros que tengan
 * 	el bit BIT(0-9) a COND (0 || 1)
 * 	En esta funcion recae una parte de la optimizacion
 *  TODO - comprobar que camino es el mas rapido para pasar de un st a otro -
 *  	 - rab o rrab -
 * */
void	move(t_stack *st, t_list *from, t_list *to, char bit)
{
	int		n;
	int		num;
	char	cond;

	cond = 0;
	if (from == st->b)
		cond = 1;
	n = st->total;
	while (n--)
	{
		num = ((t_num *)(from->content))->order;
		if (check_bit(num, bit) == cond)
			pab(st, &to, &from);
		else
			rab(st, &from, &to);
	}
	n = st->nb;
	if (from == st->a)
		n = st->na;
	while (n--)
		pab(st, &to, &from);
}

int	ordered(t_list *l)
{
	t_list	*l1;
	t_list	*l2;
	t_list	*last;

	last = ft_lstlast(l);
	l1 = l;
	l2 = l1->next;
	while (((t_num *)(l1->content))->num < ((t_num *)(l2->content))->num && l2)
	{
		l1 = l2;
		if (!(l1->next))
			return (1);
		l2 = l1->next;
	}
	return (0);
}

/*
 * Llevar los 0 del bit 0 a B
 * Llevar los 1 del bit 1 a A
 * Llevar los 0 del bit 2 a B
 * Llevar los 1 del bit 3 a A
 * Llevar los 0 del bit 4 a B
 * ...
 * Llevar los 1 del bit n a A
 * Llevar los 0 del bit n a B
 * */
void	push_swap(t_stack *st)
{
	int		n;
	char	bit;

	if (ordered(st->a))
		return ;
	if (st->total <= 5)
		return (order5only(st));
	n = 0;
	bit = check_max_bit(st->total - 1);
	while (n <= bit)
	{
		if (n % 2)
			move(st, st->b, st->a, n);
		else
			move(st, st->a, st->b, n);
		n++;
	}
	n = st->total;
	if (!(st->na))
		while (n--)
			pab(st, &st->a, &st->b);
	uporder(st, st->a, st->b, 0);
}
