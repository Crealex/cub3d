/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:42:09 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/16 13:02:24 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c)
{
	return (write(1, &c, 1));
}

int	print_s(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i])
	{
		if (print_c(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	print_di(int n)
{
	int	count;
	int	var;

	count = 0;
	if (n == -2147483648)
		return (print_s("-2147483648"));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = n * -1;
		count += 1;
	}
	if (n > 9)
	{
		var = print_di(n / 10);
		if (var == -1)
			return (-1);
		count += var;
	}
	var = print_c((n % 10) + '0');
	if (var == -1)
		return (-1);
	return (count + var);
}

int	print_u(unsigned int n)
{
	int	count;
	int	var;

	count = 0;
	if (n > 9)
	{
		var = print_u(n / 10);
		if (var == -1)
			return (-1);
		count += var;
	}
	count += print_c((n % 10) + '0');
	return (count);
}
