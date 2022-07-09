/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:14:17 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/09 04:42:09 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
typedef	struct s_num
{
	int	num;
	int	order;
}				t_num;
typedef struct s_stack
{
	int		na;
	int		nb;
	t_list	*a;
	t_list	*b;
}				t_stack;
int	push_swap(t_stack *st);
void	parse_args(int argc, char **argv, t_stack *st);
void	print_status(t_stack st);


#endif
