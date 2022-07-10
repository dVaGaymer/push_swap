/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:27:00 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/10 02:10:56 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include "color.h"
		#include "stdio.h"

void	mapper(t_stack st, int n)
{
	int		red;
	int		green;
	int		blue;
	char	*color;

	green = 0;
	red = *(st.crange) + ((*(st.crange + 1) - *(st.crange)) / st.total) * n;
	blue = 255 - red;
	color = ft_itoa(red);
	ft_printf("\e[38;2;%d;%d;%dm", red, green, blue);
}

void	lstorder(t_stack *stack)
{
	int		n;
	int		max;
	t_list	*l;

	l = stack->a;
	n = stack->na - 1;
	max = 2147483647;
	while (n >= 0)
	{
		l = ft_lstmax(stack->a, max);
		((t_num *)(l->content))->order = n;
					ft_printf("|||%d|||", ((t_num *)(l->content))->order);
					fflush(stdout);
		max = ((t_num *)(l->content))->num;
		n--;
	}
}

t_list	*ft_lstmax(t_list *lst, int	limit)
{
	t_list	*l;
	int		max;
	int		aux;

	max = -2147483648;
	if (!lst)
		return (0);
	while (lst->next)
	{
		aux = (int)((t_num *)(lst->content))->num; 
		if (aux > max && aux < limit)
		{
			max = aux;
			l = lst;
		}
		lst = lst->next;
	}
	aux = (int)((t_num *)(lst->content))->num; 
	if (aux > max && aux < limit)
	{
		max = aux;
		l = lst;
	}
	return (l);
}
