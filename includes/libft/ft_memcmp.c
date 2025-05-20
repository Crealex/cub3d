/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:37 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/09 14:24:49 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*temps1;
	const unsigned char	*temps2;

	i = 0;
	temps1 = s1;
	temps2 = s2;
	while (i < n)
	{
		if (temps1[i] != temps2[i])
		{
			return (temps1[i] - temps2[i]);
		}
		i++;
	}
	if (i >= n)
		return (0);
	return (temps1[i] - temps2[i]);
}
