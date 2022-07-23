/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:28:12 by alopez-g          #+#    #+#             */
/*   Updated: 2020/07/12 03:37:59 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	aux;
	char	*str;

	aux = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(sizeof(char), 1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	*(str + len) = 0;
	while (*(s + start + aux) && aux < len)
	{
		*(str + aux) = *(s + start + aux);
		aux++;
	}
	return (str);
}
