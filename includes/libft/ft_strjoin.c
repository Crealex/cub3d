/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:03:13 by atomasi           #+#    #+#             */
/*   Updated: 2025/03/11 11:08:41 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

static char	*valid_str(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	char	*result;

	i1 = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (valid_str(s1, s2));
	result = malloc((len(s1) + len(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i1])
	{
		result[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		result[i1] = s2[i2];
		i1++;
		i2++;
	}
	result[i1] = '\0';
	return (result);
}
