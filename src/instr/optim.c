/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:49:05 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/27 00:32:50 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "push_swap.h"
#include "ft_printf.h"

/*
 *
 * Eliminar parejas redundantes de PA y PB
 * Buscar un rango con el mismo numero de PA que de PB
 * Eliminar todas las instrucciones de ese rango
 *
 * */
void	optimize(t_stack *st)
{
	int		na;
	int		nb;
	t_list	*first;
	t_list	*last;
	t_list	*ins;

	(void)first;
	(void)last;
	na = 0;
	nb = 0;
	ins = st->i;
	while (ins)
	{
		if ((t_instr)ins->content == pa)
		{
			na++;
		}
		else if ((t_instr)ins->content == pb)
		{
			nb++;
		}
		if (((t_instr)ins->content != pa && (t_instr)ins->content != pb) || !(ins->next))
		{
			if (nb > 0 && na > 0)
				ft_printf("A(%d) B(%d)\n", na, nb);
			na = 0;
			nb = 0;
		}
		ins = ins->next;
	}
}
