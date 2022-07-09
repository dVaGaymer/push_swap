/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:09:48 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/08 23:28:44 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>

void	check_s(instr i)
{
	if (sa == i)
		ft_printf("sa");
	if (sb == i)
		ft_printf("sb");
	if (ss == i)
		ft_printf("ss");
}

void	check_p(instr i)
{
	if (pa == i)
		ft_printf("pa");
	if (pb == i)
		ft_printf("pb");
}

void	check_r(instr i)
{
	if (ra == i)
		ft_printf("ra");
	if (rb == i)
		ft_printf("rb");
	if (rr == i)
		ft_printf("rr");
}

void	check_rr(instr i)
{
	if (rra == i)
		ft_printf("rra");
	if (rrb == i)
		ft_printf("rrb");
	if (rrr == i)
		ft_printf("rrr");
}

void	exec_instr(t_stack *st, instr *i)
{
	ft_printf("Exec: ");
	while (*i)
	{
		(*i)(st);
		check_s(*i);
		write(1, " ", 1);
		check_p(*i);
		write(1, " ", 1);
		check_r(*i);
		write(1, " ", 1);
		check_rr(*i);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
