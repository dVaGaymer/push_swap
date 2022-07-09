/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:13:07 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/08 23:11:35 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

int	push_swap(t_stack *st)
{
	instr	*i;
	
	i = malloc(sizeof(instr) * 3 + 1);
	*(i) = pa;
	*(i + 1) = pa;
	*(i + 2) = pa;
	*(i + 3) = 0;

	print_status(*st);
	//exec_instr(st, i);
	print_status(*st);
	ft_lstiter(st->a, free);
	ft_lstiter(st->b, free);
	return (0);
}
