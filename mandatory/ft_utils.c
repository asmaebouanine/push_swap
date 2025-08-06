/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:43:59 by asbouani          #+#    #+#             */
/*   Updated: 2025/08/06 11:31:03 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	ft_error(char *str)
{
	write (2, str, ft_strlen(str));
	exit(1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
long	ft_check(long result, int sign, int c)
{
	if (c >= 20 || result > 9223372036854775807)
	{
		if (sign == -1)
			return (-2147483649);
		else
			return (2147483648);
	}
	return (sign * result);
}


long	ft_atoi(const char *str)
{
	int			i;
	int			c;
	int			sign;
	long		result;

	i = 0;
	c = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
		if (result != 0)
			c++;
	}
	return (ft_check(result, sign, c));
}
