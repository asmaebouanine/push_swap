/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:21:44 by asbouani          #+#    #+#             */
/*   Updated: 2025/03/09 14:21:37 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free(char **arr, int i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static int	ft_countw(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word);
}

static char	*ft_putword(char *word, char const *s, int i, int len)
{
	int	j;

	j = 0;
	while (len > 0)
	{
		word[j] = s[i - len];
		j++;
		len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_word(char const *s, char c, char **arr, int nword)
{
	int	i;
	int	word;
	int	lword;

	i = 0;
	word = 0;
	lword = 0;
	while (nword > word)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			lword++;
		}
		arr[word] = (char *)malloc(sizeof(char) * (lword + 1));
		if (!arr[word])
			return (ft_free(arr, word));
		ft_putword(arr[word], s, i, lword);
		lword = 0;
		word++;
	}
	arr[word] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	nword;

	if (!s)
		return (NULL);
	nword = ft_countw(s, c);
	arr = (char **)malloc(sizeof(char *) * (nword + 1));
	if (!arr)
		return (NULL);
	arr = ft_split_word (s, c, arr, nword);
	return (arr);
}
