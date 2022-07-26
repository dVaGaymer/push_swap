/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:43:35 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/26 18:53:05 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	check_bit(int num, char bit)
{
	return (!(!(num & (0x1 << bit))));
}

char	check_max_bit(int num)
{
	char	n;

	n = 31;
	while (n--)
	{
		if (check_bit(num, n))
			return (n);
	}
	return (0);
}
