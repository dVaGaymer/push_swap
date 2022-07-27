/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                       |*---------------------*|   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:13:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/27 22:06:09 by alopez-g         ###   ########.fr       */
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

void	exit_on_error(int err)
{
	if (!err)
		return ;
	else if (err != 1)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	st_init(t_stack *st)
{
	st->a = 0;
	st->b = 0;
	st->i = 0;
	*(st->crange) = 0;
	*(st->crange + 1) = 255;
}

void	st_clear(t_stack *st)
{
	ft_lstclear(&(st->a), free);
	ft_lstclear(&(st->b), free);
	ft_lstclear(&(st->i), 0);
}

int	main(int argc, char **argv)
{
	t_stack	st;

	st_init(&st);
	exit_on_error(parse_args(argc - 1, argv + 1, &st));
	push_swap(&st);
	print_instr(&st);
	st_clear(&st);
	return (0);
}
