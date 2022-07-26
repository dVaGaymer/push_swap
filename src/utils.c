/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:27:04 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/26 16:11:29 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include "color.h"

int	parse_args(int argc, char **argv, t_stack *st)
{
	t_num		*n;
	t_list		*l;

	if (!argc)
		return (1);
	st->na = argc--;
	st->total = st->na;
	st->nb = 0;
	while (argc-- >= 0)
	{
		n = malloc(sizeof(t_num));
		n->num = ft_atoi(*(argv++));
		if ((n->num == 0 && **(argv - 1) != 48)
			|| n->num > 2147483647 || n->num < -2147483648)
			return (2);
		l = ft_lstnew((void *)n);
		ft_lstadd_back(&(st->a), l);
	}
	lstorder(st);
	return (0);
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
