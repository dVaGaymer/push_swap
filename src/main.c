/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:13:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/07 19:10:55 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

t_stacks	parse_args(int argc, char **argv)
{
	char		aux;
	int			*n;
	t_stacks	s;
	t_list		*l;

	aux = 0;
	if (!argc)
	{
		write(1, "Usage: push_swap ...\n", 21);
		exit (1);
	}
	s.na = argc--;
	s.nb = 0;
	while (argc-- >= 0)
	{
		n = malloc(sizeof(int));
		*n = ft_atoi(*(argv++));
		l = ft_lstnew((void *)n);
		ft_lstadd_back(&s.a, l);
	}
	return (s);
}

void	print_content(void	*content)
{
	printf("%-5d", *((int *)content));
}

void	ft_print_content(void	*content)
{
	ft_printf("%-5d", *((int *)content));
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	s = parse_args(argc - 1, argv + 1);
	ft_lstiter(s.a, ft_print_content);
	write(1, "\n", 1);
	ft_lstiter(s.a, print_content);
	ft_lstiter(s.a, free);
	ft_lstiter(s.b, free);
	return (0);
}
