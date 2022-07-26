/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:09:48 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/26 19:15:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>

void	check_s(t_instr i)
{
	if (sa == i)
		ft_printf("sa");
	if (sb == i)
		ft_printf("sb");
	if (ss == i)
		ft_printf("ss");
}

void	check_p(t_instr i)
{
	if (pa == i)
		ft_printf("pa");
	if (pb == i)
		ft_printf("pb");
}

void	check_r(t_instr i)
{
	if (ra == i)
		ft_printf("ra");
	if (rb == i)
		ft_printf("rb");
	if (rr == i)
		ft_printf("rr");
}

void	check_rr(t_instr i)
{
	if (rra == i)
		ft_printf("rra");
	if (rrb == i)
		ft_printf("rrb");
	if (rrr == i)
		ft_printf("rrr");
}

void	print_instr(t_stack *st)
{
	t_list	*ins;

	ins = st->i;
	while (ins)
	{
		check_s((t_instr)ins->content);
		check_p((t_instr)ins->content);
		check_r((t_instr)ins->content);
		check_rr((t_instr)ins->content);
		ft_putchar_fd('\n', 1);
		ins = ins->next;
	}
}
