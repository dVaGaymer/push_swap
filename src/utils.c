/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:27:04 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/09 04:43:12 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	parse_args(int argc, char **argv, t_stack *st)
{
	char		aux;
	int			*n;
	t_list		*l;

	aux = 0;
	if (!argc)
	{
		write(1, "Usage: push_swap ...\n", 21);
		exit (1);
	}
	st->na = argc--;
	st->nb = 0;
	while (argc-- >= 0)
	{
		n = malloc(sizeof(int));
		*n = ft_atoi(*(argv++));
		l = ft_lstnew((void *)n);
		ft_lstadd_back(&(st->a), l);
	}
}

void	print_status(t_stack st)
{
	int		nmax;

	nmax = st.na;
	if (st.nb > st.na)
		nmax = st.nb;
	while (nmax > 0)
	{
		if (nmax <= st.na)
		{
			ft_printf("%d ", *((int *)(st.a)->content));
			st.a = st.a->next;
		}
		else
			write(1, "  ", 2);
		if (nmax <= st.nb)
		{
			ft_printf("%d", *((int *)(st.b)->content));
			st.b = st.b->next;
		}
		write(1, "\n", 1);
		nmax--;
	}
	ft_printf("- -\na b\n----------------\n");
}
