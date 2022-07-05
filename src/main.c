/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:13:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/05 23:58:38 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

//TODO STACKS ARE INT
typedef struct	s_stacks
{
	char	*a;
	char	*b;
}				t_stacks;

t_stacks	parse_args(int argc, char **argv)
{
	char		*a;
	char		*b;
	char		aux;
	t_stacks	stacks;

	aux = 0;
	if (!argc)
	{
		write(1, "Usage: push_swap ...\n", 21);
		exit (1);
	}
	a = malloc(sizeof(int) * argc + 1);
	b = malloc(sizeof(int) * argc-- + 1);
	*(b + argc + 1) = 0;
	*(a + argc + 1) = 0;
	stacks.b = b;
	stacks.a = a;
	while (argc-- >= 0)
		*(a + aux++) = **(argv++);
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stacks stacks;

	stacks = parse_args(argc - 1, argv + 1);
	ft_printf("%s", stacks.a);
	return (0);
}
