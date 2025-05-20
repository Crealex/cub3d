/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:53:24 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/09 14:24:54 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tempdest;
	const unsigned char	*tempsrc;

	i = 0;
	if (!dst && !src)
		return (NULL);
	tempdest = dst;
	tempsrc = src;
	while (i < n)
	{
		tempdest[i] = tempsrc[i];
		i++;
	}
	return (dst);
}
