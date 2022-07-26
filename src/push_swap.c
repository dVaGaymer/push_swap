/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:13:07 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/26 18:03:39 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"
#include "ft_printf.h"
#include "libft.h"

void	uporder(t_stack *st, t_list *sel, t_list *other, int order)
{
	t_list	*lst;
	int		cnt;
	int		size;

	size = st->na;
	cnt = 0;
	lst = sel;
	while (((t_num *)(lst->content))->order != order)
	{
		lst = lst->next;
		cnt++;
	}
	if (cnt <= (size / 2))
	{
		while (cnt--)
			rab(st, &sel, &other);
	}
	else
	{
		cnt = size - cnt;
		while (cnt--)
			rrab(st, &sel, &other);
	}
}

int	smaller_order(t_list *l)
{
	int		min;

	min = 0xFFFFFF;
	while (l)
	{
		if (((t_num *)(l->content))->order < min)
			min = ((t_num *)(l->content))->order;
		l = l->next;
	}
	return (min);
}

void	order3only(t_stack *st)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (int)((t_num *)(st->a->content))->order;
	n2 = (int)((t_num *)(st->a->next)->content)->order;
	if (st->a->next->next)
		n3 = (int)((t_num *)(st->a->next->next)->content)->order;
	else if (n1 > n2 && !(st->a->next->next))
		sa(st);
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
	{
		order3only(st);
		return ;
	}
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

char	check_bit(int num, char bit)
{
	return !(!(num & (0x1 << bit)));
}

char	check_max_bit(int num)
{
	char	n;

	n = 31;
	while (n--)
	{
		if (check_bit(num, n))
			return (n);
	}
	return (0);
}

/*
 * Mueve de un stack a otro todos los numeros que tengan
 * 	el bit BIT(0-9) a COND (0 || 1)
 * 	En esta funcion recae una parte de la optimizacion
 *  TODO - comprobar que camino es el mas rapido para pasar de un st a otro -
 *  	 - rab o rrab -
 * */
void	move(t_stack *st, t_list *from, t_list *to, char bit, char cond)
{
	int		n;
	int		num;

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

void	move_all(t_stack *st, t_list *from,  t_list *to)
{
	int	n;

	n = st->total;
	while (n--)
		pab(st, &to, &from);
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
void	test(t_stack *st)
{
	int		n;
	char	bit;

	n = 0;
	bit = check_max_bit(st->total - 1);
	while (n <= bit)
	{
		if (n % 2)
			move(st, st->b, st->a, n, 1);
		else
			move(st, st->a, st->b, n, 0);
		n++;
	}
	if (!(st->na))
		move_all(st, st->b, st->a);
	uporder(st, st->a, st->b, 0);
}

int	push_swap(t_stack *st)
{
	//print_status(*st);
	//if (st->total <= 5)
	//	order5only(st);
	//move(st, st->a, st->b, 0, 0);
	test(st);
	print_instr(st);
	//print_status(*st);
	return (0);
}

/*
 * 
 * 
 * int		next_smaller_order(t_stack *st, t_list *sel, int order)
 * {
 * 	int		min;
 * 
 * 	min = st->total;
 * 	while (sel) 
 * 	{
 * 		if (((t_num *)(sel->content))->order < min
 * 				&& ((t_num *)(sel->content))->order > order)
 * 			min = ((t_num *)(sel->content))->order;
 * 		sel = sel->next;
 * 	}
 * 	return (min);
 * }
 * 
 * void	brute_force(t_stack *st, t_list **sel, t_list **other)
 * {
 * 	int		total;
 * 	int		cnt;
 * 
 * 	total = st->na;
 * 	cnt = 0;
 * 	if (*sel == st->b)
 * 		total = st->nb;
 * 	while (cnt < total)
 * 	{
 * 		uporder(st, *sel, *other, smaller_order(st, *sel, *other));
 * 		pab(st, other, sel);
 * 		cnt++;
 * 	}
 * 	while (cnt--)
 * 		pab(st, sel, other);
 * }
 * 
 * void	order10(t_stack *st)
 * {
 * 	int	cnt;
 * 	int	o;
 * 
 * 	cnt = 0;
 * 	pb(st);
 * 	pb(st);
 * 	pb(st);
 * 	pb(st);
 * 	pb(st);
 * 	order5only(st, st->a, st->b);
 * 	order5only(st, st->b, st->a);
 * 	while (cnt++ < 5)
 * 	{
 * 		o = ((t_num *)(st->b->content))->order;
 * 		uporder(st, st->a, st->b, next_smaller_order(st, st->a, o));
 * 		pa(st);
 * 	}
 * 	uporder(st, st->a, st->b, 0);
 * }
 * 
 * int	ordered(t_list *l)
 * {
 * 	t_list	*l1;
 * 	t_list	*l2;
 * 	t_list	*last;
 * 
 * 	last = ft_lstlast(l);
 * 	l1 = l;
 * 	l2 = l1->next;
 * 	while (((t_num *)(l1->content))->num < ((t_num *)(l2->content))->num && l2) 
 * 	{
 * 		l1 = l2;
 * 		if (!(l1->next))
 * 			return (1);
 * 		l2 = l1->next;
 * 	}
 * 	return (0);
 * }
*/
