/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:27:00 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/03 14:50:17 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include "color.h"

void	mapper(t_stack st, int n)
{
	int		red;
	int		green;
	int		blue;

	green = 0;
	red = *(st.crange) + ((*(st.crange + 1) - *(st.crange)) / st.total) * n;
	blue = 255 - red;
	ft_printf("\e[38;2;%d;%d;%dm", red, green, blue);
}

void	lstorder(t_stack *stack)
{
	int		n;
	long	max;
	t_list	*l;

	l = stack->a;
	n = stack->na - 1;
	max = (long)2147483647 + 1;
	while (n >= 0)
	{
		l = ft_lstmax(stack->a, max);
		((t_num *)(l->content))->order = n;
		max = ((t_num *)(l->content))->num;
		n--;
	}
}

t_list	*ft_lstmax(t_list *lst, long limit)
{
	t_list	*l;
	long	min;
	int		aux;

	min = (long)-2147483648 - 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		aux = ((t_num *)(lst->content))->num;
		if (aux > min && aux < limit)
		{
			min = aux;
			l = lst;
		}
		lst = lst->next;
	}
	aux = ((t_num *)(lst->content))->num;
	if (aux > min && aux < limit)
	{
		min = aux;
		l = lst;
	}
	return (l);
}
