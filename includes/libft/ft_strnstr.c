/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:59:14 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/09 14:27:16 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lj;

	i = 0;
	lj = 0;
	while (needle[lj])
		lj++;
	if (!needle[i])
		return ((char *)&haystack[i]);
	while (haystack[i] && i + lj <= len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && (j + i) < len)
			j++;
		if (j == lj)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
