/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:50:09 by asbouani          #+#    #+#             */
/*   Updated: 2025/03/16 14:23:20 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free2(char **stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		free (stack[i++]);
	}
	free(stack);
}

int	valid_instraction(char *str)
{
	char	*operation;
	char	*cp;
	char	**arr;
	int		i;

	operation = "sa sb ss pa pb ra rb rr rra rrb rrr";
	arr = ft_split(operation, ' ');
	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		cp = ft_strjoin(arr[i], "\n");
		if (!cp)
			return (ft_free2(arr), 0);
		if (ft_strcmp(cp, str) == 0)
		{
			free (cp);
			ft_free2(arr);
			return (1);
		}
		free (cp);
		i++;
	}
	return (ft_free2(arr), 0);
}

void	ft_instract(t_stack **a, t_stack **b, t_stack *stack)
{
	if (ft_strcmp(stack->op, "ra\n") == 0)
		rotate(a, NULL);
	else if (ft_strcmp(stack->op, "rb\n") == 0)
		rotate(b, NULL);
	else if (ft_strcmp(stack->op, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(stack->op, "rra\n") == 0)
		rrotate(a, NULL);
	else if (ft_strcmp(stack->op, "rrb\n") == 0)
		rrotate(b, NULL);
	else if (ft_strcmp(stack->op, "rrr\n") == 0)
		rrr(a, b);
}

void	ft_instraction(t_stack **a, t_stack **b, t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		if (ft_strcmp(stack->op, "sa\n") == 0)
			swap(a, NULL);
		else if (ft_strcmp(stack->op, "sb\n") == 0)
			swap(b, NULL);
		else if (ft_strcmp(stack->op, "ss\n") == 0)
			ss(a, b);
		else if (ft_strcmp(stack->op, "pa\n") == 0)
			push_a(a, b, NULL);
		else if (ft_strcmp(stack->op, "pb\n") == 0)
			push_b(a, b, NULL);
		else
			ft_instract(a, b, stack);
		stack = stack->next;
	}
}

int	check_sort(t_stack **a, t_stack **b)
{
	char	*inst;
	t_stack	*lst;

	inst = NULL;
	lst = NULL;
	inst = get_next_line(0);
	while (inst)
	{
		if (!valid_instraction(inst))
		{
			free(inst);
			ft_clear(lst);
			ft_clear(*a);
			ft_error("Error\n");
		}
		ft_add_back(&lst, stack_new(inst));
		free(inst);
		inst = get_next_line(0);
	}
	ft_instraction(a, b, lst);
	if (!(*b) && is_sorted(*a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_clear(lst), 0);
}
