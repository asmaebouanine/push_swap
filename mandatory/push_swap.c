/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:25:42 by asbouani          #+#    #+#             */
/*   Updated: 2025/03/18 23:28:08 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack);
		*stack = (*stack)->next;
		free(tmp);
	}
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (!ft_isdigit(str[i]))
			ft_error("Error\n");
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error("Error\n");
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack, int nb)
{
	while (stack)
	{
		if (stack->value == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	check_args(char *av, t_stack **stack_a)
{
	int		j;
	long	nb;
	char	**str;
	t_stack	*node;

	if (av[0] == '\0')
		ft_error("Error\n");
	str = ft_split(av, ' ');
	if (!str || !*str)
		ft_error("Error\n");
	j = 0;
	while (str[j])
	{
		is_num(str[j]);
		nb = ft_atoi(str[j]);
		if (nb > 2147483647 || nb < -2147483648)
			ft_error("Error\n");
		if (is_duplicate(*stack_a, nb))
			ft_error("Error\n");
		node = ft_stack_new(nb);
		ft_add_back((stack_a), &node);
		free(str[j]);
		j++;
	}
	free(str);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	while (i < ac)
		check_args(av[i++], &a);
	ft_index(a);
	if (!is_sorted(a))
	{
		if (stack_size(a) <= 3)
			sort_three(&a);
		else if (stack_size(a) <= 5)
			sort_five(&a, &b);
		else
			ft_sort(&a, &b, stack_size(a));
	}
	(free_stack(&a), free_stack(&b));
}
