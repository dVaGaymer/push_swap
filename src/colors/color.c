/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:27:00 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/09 18:28:52 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include "color.h"

void	mapper(int a, int b, int c, int d, int n)
{
	int		red;
	int		green;
	int		blue;
	char	*color;

	green = 0;
	red = c + (d-c)/(b-a) * (n - a);
	blue = 255 - red;
	color = ft_itoa(red);
	ft_printf("\e[38;2;%d;%d;%dm", red, green, blue);
}

void	order(t_stack *stack)
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
		ft_printf("(%d)", ((t_num *)(l->content))->num);
		((t_num *)(l->content))->order = n;
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
