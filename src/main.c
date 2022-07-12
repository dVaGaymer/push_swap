/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:13:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/12 06:56:30 by alopez-g         ###   ########.fr       */
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

t_instr	str_to_instr(char *str)
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
	else if (*str == 'r' && *(str + 1) == 'r' &&
			(*(str +  2) == 'r' || *(str + 2) == 'a' || *(str + 2) == 'b'))
	{
		if (*(str + 2) == 'a')
			return &rra;
		if (*(str + 2) == 'b')
			return &rrb;
		if (*(str + 2) == 'r')
			return &rrr;
	}
	else if (*str == 'r')
	{
		if (*(str + 1) == 'a')
			return &ra;
		if (*(str + 1) == 'b')
			return &rb;
		if (*(str + 1) == 'r')
			return &rr;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	st;
	int		moves;
	int		err;

	st.a = 0;
	st.b = 0;
	*(st.crange) = 0;
	*(st.crange + 1) = 255;
	err = parse_args(argc - 1, argv + 1, &st);
	if (err == 1)
		exit(1);
	else if (err)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	moves = push_swap(&st);
	ft_lstiter(st.a, free);
	ft_lstiter(st.b, free);
	return (0);
}
