/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:34:06 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/09 14:25:19 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counterc(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int	malloc_words(char **res, const char *s, char c)
{
	int	word;
	int	countl;
	int	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		countl = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			countl++;
			i++;
		}
		if (countl > 0)
		{
			res[word] = malloc(countl + 1);
			if (!res[word++])
				return (0);
		}
	}
	res[word] = NULL;
	return (1);
}

static void	fill(char **res, const char *s, char c)
{
	int	i;
	int	jres;
	int	ires;

	i = 0;
	jres = 0;
	ires = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			res[ires][jres] = '\0';
			ires++;
			jres = 0;
			while (s[i] == c)
				i++;
			continue ;
		}
		res[ires][jres++] = s[i++];
	}
	if (ires < counterc(s, c))
		res[ires][jres] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	word_count = counterc(s, c);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (res == NULL)
		return (NULL);
	if (!malloc_words(res, s, c))
	{
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (NULL);
	}
	if (word_count > 0)
		fill(res, s, c);
	return (res);
}
