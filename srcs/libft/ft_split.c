/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:36:00 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/03 17:36:01 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_words(const char *str, char c)
{
	size_t	word;

	word = 0;
	while (*str)
	{
		if (*str != c)
		{
			word++;
			while (*str != c && *str)
				str++;
		}
		else
			str++;
	}
	return (word);
}

char	*malloc_word(const char *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**splited;

	splited = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!splited || !s)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			splited[i] = malloc_word(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	splited[i] = 0;
	return (splited);
}
