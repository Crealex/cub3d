/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:49:28 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/16 13:02:56 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	print_c(int c);
int	print_s(char *str);
int	print_p(unsigned long p);
int	print_di(int n);
int	print_u(unsigned int n);
int	print_x(unsigned int n);
int	print_xmaj(unsigned int n);

#endif
