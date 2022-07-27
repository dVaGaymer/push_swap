/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                       |*---------------------*|   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:13:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/27 03:05:18 by alopez-g     +-----------------------+   */
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

#ifdef DEBUG

void	check_leaks(void)
{
	system("leaks push_swap");
}

#endif

int	main(int argc, char **argv)
{
	t_stack	st;
	int		err;

	st.a = 0;
	st.b = 0;
	st.i = 0;
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
	push_swap(&st);
	//optimize(&st);
	print_instr(&st);
	ft_lstclear(&st.a, free);
	ft_lstclear(&st.b, free);
	ft_lstclear(&st.i, 0);
	return (0);
}
