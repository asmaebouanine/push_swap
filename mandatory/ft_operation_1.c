/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:04:06 by asbouani          #+#    #+#             */
/*   Updated: 2025/03/10 21:32:21 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char *str)
{
	t_stack	*tmp;

	if (!*stack ||!(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_add_back(stack, &tmp);
	if (str)
		write (1, str, ft_strlen(str));
}

void	rr(t_stack **sa, t_stack **sb)
{
	rotate(sa, NULL);
	rotate(sb, NULL);
	write (1, "rr\n", 3);
}

void	rrotate(t_stack **stack, char *str)
{
	t_stack	*tmp;
	t_stack	*find;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = ft_last(*stack);
	find = *stack;
	while (find->next->next)
		find = find->next;
	find->next = NULL;
	ft_add_front(stack, tmp);
	if (str)
		write (1, str, ft_strlen(str));
}

void	rrr(t_stack **sa, t_stack **sb)
{
	rrotate(sa, NULL);
	rrotate(sb, NULL);
	write (1, "rrr\n", 4);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
