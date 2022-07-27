/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:49:05 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/28 00:00:39 by alopez-g         ###   ########.fr       */
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
	t_list	*ins;
	t_list	*aux;
	char	flag;

	ins = st->i;
	while (ins->next)
	{
		flag = 0;
		aux = 0;
		if ((ins->content == pa && ins->next->content == pb)
			|| (ins->content == pb && ins->next->content == pa))
		{
			if (ins == st->i)
				aux = st->i->next->next;
			ft_lstdelone(&(ins), 0);
			ft_lstdelone(&(ins), 0);
			if (aux)
				st->i = aux;
			flag = 1;
		}
		ins = ins->next;
		if (flag)
			ins = st->i;
	}
}
