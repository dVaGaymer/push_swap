/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:13:02 by alopez-g          #+#    #+#             */
/*   Updated: 2020/07/07 17:14:48 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	aux;

	aux = 0;
	if (!(s = malloc(count * size)))
		return (0);
	while (aux < (count * size))
	{
		*(unsigned char *)(s + aux) = 0;
		aux++;
	}
	return (s);
}
