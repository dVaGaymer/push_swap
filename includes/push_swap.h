/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:14:17 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/09 06:43:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
typedef struct s_stack
{
	int		total;
	int		na;
	int		nb;
	t_list	*a;
	t_list	*b;
}				t_stack;
int	push_swap(t_stack *st);
void	parse_args(int argc, char **argv, t_stack *st);
void	print_status(t_stack st);


#endif
