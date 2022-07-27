/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:49:05 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/27 22:06:42 by alopez-g         ###   ########.fr       */
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
 * void	optimize(t_stack *st)
 * {
 * 	int		na;
 * 	int		nb;
 * 	t_list	*ins;
 * 	t_list	*nx;
 * 
 * 	na = 0;
 * 	nb = 0;
 * 	ins = st->i;
 * 	while (ins)
 * 	{
 * 		nx = ins->next;
 * 		if (!nx)
 * 			return ;
 * 		if ((ins->content == pa && nx->content == pb)
 * 				|| (ins->content == pb && nx->content == pa))
 * 		{
 * 			ft_lstdelone(&nx, 0);
 * 			ft_lstdelone(&ins, 0);
 * 			ins = st->i;
 * 		}
 * 		ins = ins->next;
 * 	}
 * }
 * */
