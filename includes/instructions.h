/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:37:51 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/12 06:55:44 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "push_swap.h"

typedef void	(*t_instr)(t_stack *stack);
void	sab(t_stack *stacks, char sel);
void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
void	ss(t_stack *stacks);
void	pab(t_stack *stacks, char sel);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);
void	rab(t_stack *stacks, char sel);
void	ra(t_stack *stacks);
void	rb(t_stack *stacks);
void	rr(t_stack *stacks);
void	rrab(t_stack *stacks, char sel);
void	rra(t_stack *stacks);
void	rrb(t_stack *stacks);
void	rrr(t_stack *stacks);
void	exec_instr(t_stack *st);
void	print_instr(t_stack *st);

#endif
