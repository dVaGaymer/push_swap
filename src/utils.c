/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:27:04 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/03 18:03:49 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include "color.h"

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
			mapper(st, (int)((t_num *)(st.a->content))->order);
			ft_printf("%d ", (int)((t_num *)(st.a->content))->num);
			ft_printf("\e[0m");
			st.a = st.a->next;
		}
		write(1, "|", 1);
		if (nmax-- <= st.nb)
		{
			mapper(st, (int)((t_num *)(st.b->content))->order);
			ft_printf("%d", (int)((t_num *)(st.b->content))->num);
			ft_printf("\e[0m");
			st.b = st.b->next;
		}
		write(1, "\n", 1);
	}
	ft_printf("- -\na b\n----------------\n");
}

void	st_clear(t_stack *st)
{
	ft_lstclear(&(st->a), free);
	ft_lstclear(&(st->b), free);
	ft_lstclear(&(st->i), 0);
}

void	st_init(t_stack *st)
{
	st->a = 0;
	st->b = 0;
	st->i = 0;
	*(st->crange) = 0;
	*(st->crange + 1) = 255;
}
