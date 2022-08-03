/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:59:33 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/03 17:59:36 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include "color.h"

int	is_repeated(t_stack *st, int num)
{
	t_list	*l;

	l = st->a;
	while (l)
	{
		if (num == (int)((t_num *)(l)->content)->num)
			return (1);
		l = l->next;
	}
	return (0);
}

int	free_arg(char **subarg)
{
	char	**t;

	t = subarg;
	while (*subarg)
	{
		free(*subarg);
		subarg++;
	}
	free(t);
	return (3);
}

int	each_arg(t_stack *st, char *arg)
{
	long	num;
	t_num	*n;
	t_list	*l;
	char	**subargs;
	char	**t;

	if (ft_strisalpha(arg))
		return (3);
	subargs = ft_split(arg, 32);
	t = subargs;
	while (*subargs)
	{
		num = ft_atoi(*subargs);
		if (is_repeated(st, num)
			|| (num == 0 && **subargs != 48) || num > MAX_INT || num < MIN_INT)
			return (free_arg(t));
		n = malloc(sizeof(t_num));
		n->num = num;
		l = ft_lstnew((void *)n);
		ft_lstadd_back(&(st->a), l);
		subargs++;
		st->na++;
	}
	free_arg(t);
	return (0);
}

/*
 * 1 - NO ARGS
 * 2 - ARG NOT A NUMBER
 * 3 - REPEATED NUMBER
 * */
int	parse_args(int argc, char **argv, t_stack *st)
{
	int	err;

	if (!argc)
		return (1);
	st->na = 0;
	st->nb = 0;
	while (--argc >= 0)
	{
		err = each_arg(st, *argv++);
		if (err)
			return (err);
	}
	st->total = st->na;
	lstorder(st);
	return (0);
}
