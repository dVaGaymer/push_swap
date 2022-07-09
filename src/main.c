/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:13:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/09 04:40:42 by alopez-g         ###   ########.fr       */
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

instr	str_to_instr(char *str)
{
	if (*str == 's')
	{
		if (*(str + 1) == 'a')
			return &sa;
		if (*(str + 1) == 'b')
			return &sb;
		if (*(str + 1) == 's')
			return &ss;
	}
	else if (*str == 'p')
	{
		if (*(str + 1) == 'a')
			return &pa;
		if (*(str + 1) == 'b')
			return &pb;
	}
	else if (*str == 'r')
	{
		if (*(str + 1) == 'a')
			return &ra;
		if (*(str + 1) == 'b')
			return &rb;
		if (*(str + 1) == 'b')
			return &rr;
	}
	else if (*str == 'r' && (*str + 1) == 'r')
	{
		if (*(str + 2) == 'a')
			return &rra;
		if (*(str + 2) == 'b')
			return &rrb;
		if (*(str + 2) == 'r')
			return &rrr;
	}
}

int	main(int argc, char **argv)
{
	t_stack	st;
	int		moves;
	char	c[2];
	instr	i;
	char	flag;

	st.a = 0;
	st.b = 0;
	parse_args(argc - 1, argv + 1, &st);
	print_status(st);
	ra(&st);
	ra(&st);
	ra(&st);
	print_status(st);
	mapper(0, 10, 0, 255, 5);
	ft_printf("HOLA\e[0m");
	while (1)
	{
		scanf("%2s", c);
		write(1, "\n", 1);
		i = str_to_instr(c);
		i(&st);
		print_status(st);
	}
	moves = push_swap(&st);
	return (0);
}
