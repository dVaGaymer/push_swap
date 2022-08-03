/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:13:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/03 22:41:02 by alopez-g         ###   ########.fr       */
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
#define MIN_OPT 5

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
	if (ft_lstsize(st.i) > MIN_OPT)
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
	print_status(st);
	push_swap(&st);
	if (ft_lstsize(st.i) > MIN_OPT)
		optimize(&st);
	print_status(st);
	print_instr(&st);
	st_clear(&st);
	return (0);
}

#endif
