/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:58:50 by asbouani          #+#    #+#             */
/*   Updated: 2025/03/14 16:29:53 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	while (s1[i])
		i++;
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cp;
	int		i;
	int		j;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	cp = (char *)malloc(sizeof(char) * (len + 1));
	if (!cp)
		return (NULL);
	i = -1;
	while (s1[++i])
		cp[i] = s1[i];
	j = -1;
	while (s2[++j])
		cp[i + j] = s2[j];
	cp[i + j] = '\0';
	return (cp);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if (str[i] == (char)c)
		return (str + i);
	return (NULL);
}
