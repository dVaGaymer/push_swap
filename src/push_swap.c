/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:13:07 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/25 06:35:52 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"
#include "ft_printf.h"
#include "libft.h"

void	order3only(t_stack *st, t_list *sel, t_list *other)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (int)((t_num *)(sel->content))->order;
	n2 = (int)((t_num *)(sel->next)->content)->order;
	if (sel->next->next)
		n3 = (int)((t_num *)(sel->next->next)->content)->order;
	else if (n1 > n2 && !(sel->next->next))
		sab(st, &sel, &other);
	if (n1 > n2 && n1 < n3 && n2 < n3 && sel->next->next)
		sab(st, &sel, &other);
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		rrab(st, &sel, &other);
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		rab(st, &sel, &other);
	else if (n2 > n3)
	{
		sab(st, &sel, &other);
		if (n1 > n2 && n1 > n3)
			rrab(st, &sel, &other);
		if (n1 < n2 && n1 < n3)
			rab(st, &sel, &other);
	}
}

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

int		smaller_order(t_stack *st, t_list *sel, t_list *other)
{
	int		min;
	other = 0;

	min = st->total;
	while (sel) 
	{
		if (((t_num *)(sel->content))->order < min)
			min = ((t_num *)(sel->content))->order;
		sel = sel->next;
	}
	return (min);
}

int		next_smaller_order(t_stack *st, t_list *sel, int order)
{
	int		min;

	min = st->total;
	while (sel) 
	{
		if (((t_num *)(sel->content))->order < min
				&& ((t_num *)(sel->content))->order > order)
			min = ((t_num *)(sel->content))->order;
		sel = sel->next;
	}
	return (min);
}

void	brute_force(t_stack *st, t_list **sel, t_list **other)
{
	int		total;
	int		cnt;

	total = st->na;
	cnt = 0;
	if (*sel == st->b)
		total = st->nb;
	while (cnt < total)
	{
		uporder(st, *sel, *other, smaller_order(st, *sel, *other));
		pab(st, other, sel);
		cnt++;
	}
	while (cnt--)
		pab(st, sel, other);
}

void	order5only(t_stack *st, t_list *sel, t_list *other)
{
	if (!sel->next)
		return ;
	if (!sel->next->next || !sel->next->next->next)
	{
		order3only(st, sel, other);
		return ;
	}
	if (sel->next->next->next->next == 0)
	{
		uporder(st, sel, other, smaller_order(st, sel, other));
		pb(st);
		order3only(st, sel, other);
		pa(st);
	}
	else
	{
		uporder(st, sel, other, smaller_order(st, sel, other));
		pab(st, &other, &sel);
		uporder(st, sel, other, smaller_order(st, sel, other));
		pab(st, &other, &sel);
		//order3only(st, st->a);
		brute_force(st, &sel, &other);
		pab(st, &sel, &other);
		pab(st, &sel, &other);
	}
}

void	order10(t_stack *st)
{
	int	cnt;
	int	o;

	cnt = 0;
	pb(st);
	pb(st);
	pb(st);
	pb(st);
	pb(st);
	order5only(st, st->a, st->b);
	order5only(st, st->b, st->a);
	while (cnt++ < 5)
	{
		o = ((t_num *)(st->b->content))->order;
		uporder(st, st->a, st->b, next_smaller_order(st, st->a, o));
		pa(st);
	}
	uporder(st, st->a, st->b, 0);
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

char	check_bit(int num, char bit)
{
	return (num & (0x1 << bit));
}

void	move(t_stack *st, t_list *from, t_list *to, char bit, char cond)
{
	int		n;
	int		num;
	char	bits;
	
	bits = 0;
	n = st->na;
	num = ((t_num *)(from->content))->order;
	ft_printf("|%d|", st->na);
	while (n--)
	{
		num = ((t_num *)(from->content))->order;
		if (check_bit(num, bit) == cond)
			pab(st, &to, &from);
		else
			rab(st, &from, &to);
	}
}

void	test(t_stack *st)
{
	int		n;
	char	bit;

	n = 0;
	bit = 1;
	while (n++ < 2)
	{
		move(st, st->a, st->b, bit--, 0);
		print_status(*st);
	}
}

int	push_swap(t_stack *st)
{
	print_status(*st);
	//move(st, st->a, st->b, 0, 0);
	test(st);
	print_status(*st);
	//brute_force(st, &st->a, &st->b);
	//order5only(st, st->a, st->b);
	//order10(st);
	//print_status(*st);
	//print_instr(st);
	//brute_force(st);
	return (0);
}
