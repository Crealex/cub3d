/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:50:33 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/09 14:24:24 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	nb;
	int	res;

	nb = n;
	res = 0;
	if (nb < 0)
	{
		res++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = malloc(sizeof(char) * (len(n) + 1));
	if (res == NULL)
		return (NULL);
	i = len(n);
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	res[i] = '\0';
	while (n > 0)
	{
		i--;
		res[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (res);
}
