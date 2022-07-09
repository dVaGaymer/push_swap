/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:37:51 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/08 22:34:14 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

#include "push_swap.h"

typedef void (*instr)(t_stack *stack);

void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
void	ss(t_stack *stacks);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);
void	ra(t_stack *stacks);
void	rb(t_stack *stacks);
void	rr(t_stack *stacks);
void	rra(t_stack *stacks);
void	rrb(t_stack *stacks);
void	rrr(t_stack *stacks);
void	exec_instr(t_stack *st, instr *i);

#endif
