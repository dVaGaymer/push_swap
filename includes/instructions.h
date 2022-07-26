/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:37:51 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/27 00:00:48 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "push_swap.h"

typedef void	(*t_instr)(t_stack *stack);
void	sab(t_stack *st, t_list **sel, t_list **other);
void	sa(t_stack *st);
void	sb(t_stack *st);
void	ss(t_stack *st);
void	pab(t_stack *st, t_list **sel, t_list **other);
void	pa(t_stack *st);
void	pb(t_stack *st);
void	rab(t_stack *st, t_list **sel, t_list **other);
void	ra(t_stack *st);
void	rb(t_stack *st);
void	rr(t_stack *st);
void	rrab(t_stack *st, t_list **sel, t_list **other);
void	rra(t_stack *st);
void	rrb(t_stack *st);
void	rrr(t_stack *st);
void	exec_instr(t_stack *st);
void	print_instr(t_stack *st);
void	optimize(t_stack *st);

#endif
