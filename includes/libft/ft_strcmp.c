/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:48:45 by atomasi           #+#    #+#             */
/*   Updated: 2025/05/20 15:06:35 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	s1u;
	unsigned char	s2u;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i])
	{
		s1u = (unsigned char)s1[i];
		s2u = (unsigned char)s2[i];
		if (s1u != s2u)
			return (s1u - s2u);
		i++;
	}
	s1u = (unsigned char)s1[i];
	s2u = (unsigned char)s2[i];
	return (s1u - s2u);
}
