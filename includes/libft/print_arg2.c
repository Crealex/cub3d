/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:40:16 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/16 13:06:40 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned int n)
{
	char	*hex;
	int		count;
	int		var;

	count = 0;
	hex = "0123456789abcdef";
	if (n > 15)
	{
		var = print_x(n / 16);
		if (var == -1)
			return (-1);
		count += var;
	}
	var = print_c(hex[n % 16]);
	if (var == -1)
		return (-1);
	count += var;
	return (count);
}

int	print_xmaj(unsigned int n)
{
	char	*hex;
	int		count;
	int		var;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n > 15)
	{
		var = print_xmaj(n / 16);
		if (var == -1)
			return (-1);
		count += var;
	}
	var = print_c(hex[n % 16]);
	if (var == -1)
		return (-1);
	count += var;
	return (count);
}

static int	print_pp(unsigned long n)
{
	char	*hex;
	int		count;
	int		var;

	count = 0;
	hex = "0123456789abcdef";
	if (n > 15)
	{
		var = print_pp(n / 16);
		if (var == -1)
			return (-1);
		count += var;
	}
	var = print_c(hex[n % 16]);
	if (var == -1)
		return (-1);
	count += var;
	return (count);
}

int	print_p(unsigned long p)
{
	int	count;

	count = 2;
	if (write (1, "0x", 2) == -1)
		return (-1);
	count += print_pp(p);
	return (count);
}
