/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 01:41:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/09 04:39:56 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// "\e[48;2;${r};${g};${b}mr${r}g${g}b${b}\e[0m"
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
