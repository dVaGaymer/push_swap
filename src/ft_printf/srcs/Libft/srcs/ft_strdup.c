/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:31:42 by alopez-g          #+#    #+#             */
/*   Updated: 2020/07/12 04:15:24 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * ((int)ft_strlen(s1) + 1))))
		return (0);
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	*(str + i) = 0;
	return (str);
}
