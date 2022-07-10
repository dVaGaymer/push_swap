/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:27:04 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/10 02:07:32 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include "color.h"

int	parse_args(int argc, char **argv, t_stack *st)
{
	char		aux;
	t_num		*n;
	t_list		*l;

	aux = 0;
	if (!argc)
		return (1);
	st->na = argc--;
	st->total = st->na;
	st->nb = 0;
	while (argc-- >= 0)
	{
		n = malloc(sizeof(t_num));
		n->num = ft_atoi(*(argv++));
		if (n->num == 0 && **(argv - 1) != 48)
			return (1);
		l = ft_lstnew((void *)n);
		ft_lstadd_back(&(st->a), l);
	}
	lstorder(st);
	return 0;
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
			mapper(st, (int)((t_num *)(st.a->content))->order);
			ft_printf("%d ", (int)((t_num *)(st.a->content))->order);
			ft_printf("\e[0m");
			st.a = st.a->next;
		}
		write(1, "|", 1);
		if (nmax-- <= st.nb)
		{
			mapper(st, (int)((t_num *)(st.b->content))->order);
			ft_printf("%d", (int)((t_num *)(st.b->content))->order);
			ft_printf("\e[0m");
			st.b = st.b->next;
		}
		write(1, "\n", 1);
	}
	ft_printf("- -\na%d b%d\n----------------\n", st.na, st.nb);
}
