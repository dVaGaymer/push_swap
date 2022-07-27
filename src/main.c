/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                       |*---------------------*|   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:13:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/28 00:09:25 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "instructions.h"
#include <stdio.h>
#include "color.h"

void	exit_on_error(t_stack *st, int err)
{
	if (!err)
		return ;
	else if (err != 1)
		ft_putstr_fd("Error\n", 2);
	st_clear(st);
	exit(1);
}

#ifndef DEBUG

int	main(int argc, char **argv)
{
	t_stack	st;

	st_init(&st);
	exit_on_error(&st, parse_args(argc - 1, argv + 1, &st));
	push_swap(&st);
	if (ft_lstsize(st.i) > 0)
		optimize(&st);
	print_instr(&st);
	st_clear(&st);
	return (0);
}

#endif

#ifdef DEBUG

void	check_leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_stack	st;

	atexit(check_leaks);
	st_init(&st);
	exit_on_error(&st, parse_args(argc - 1, argv + 1, &st));
	push_swap(&st);
	if (ft_lstsize(st.i) > 0)
		optimize(&st);
	print_instr(&st);
	st_clear(&st);
	return (0);
}

#endif
