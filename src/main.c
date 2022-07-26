/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:13:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/26 22:59:35 by alopez-g         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	st;
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
	push_swap(&st);
	print_instr(&st);
	ft_lstiter(st.a, free);
	ft_lstiter(st.b, free);
	//ft_lstiter(st.i, free);
	return (0);
}
