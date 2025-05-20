/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:34:35 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/09 14:24:42 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*temp;
	unsigned char		cu;

	i = 0;
	temp = (const unsigned char *)s;
	cu = (unsigned char)c;
	while (i < n)
	{
		if (temp[i] == cu)
		{
			return ((void *)&temp[i]);
		}
		i++;
	}
	return (0);
}
