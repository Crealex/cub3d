/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:48:25 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/16 13:06:17 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	short_print(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count = print_di(va_arg(args, int));
	else if (c == 'c')
		count = print_c(va_arg(args, int));
	else if (c == 's')
		count = print_s(va_arg(args, char *));
	else if (c == 'p')
		count = print_p(va_arg(args, unsigned long));
	else if (c == 'u')
		count = print_u(va_arg(args, unsigned int));
	else if (c == 'x')
		count = print_x(va_arg(args, unsigned int));
	else if (c == 'X')
		count = print_xmaj(va_arg(args, unsigned int));
	else if (c == '%')
		count = print_c('%');
	return (count);
}

static int	pre_short(int *i, const char *str, va_list args)
{
	int	var;
	int	count;

	count = 0;
	if (str[*i] == '%')
	{
		(*i)++;
		if (str[*i])
		{
			var = short_print(str[*i], args);
			if (var == -1)
				return (-1);
			count += var;
		}
		else
			return (-1);
	}
	else
	{
		if (write(1, &str[*i], 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		var;

	i = 0;
	count = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		var = pre_short(&i, str, args);
		if (var == -1)
		{
			va_end(args);
			return (-1);
		}
		count += var;
		i++;
	}
	va_end(args);
	return (count);
}
