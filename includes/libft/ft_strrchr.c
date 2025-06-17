/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:59:05 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/09 14:26:02 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	cu;

	i = 0;
	cu = (unsigned char)c;
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == cu)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
