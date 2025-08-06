/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:07:34 by asbouani          #+#    #+#             */
/*   Updated: 2025/03/19 14:36:44 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **sa)
{
	if (stack_size(*sa) == 2)
	{
		if ((*sa)->value > (*sa)->next->value)
			swap(sa, "sa\n");
	}
	else if ((*sa)->value > (*sa)->next->value
		&& (*sa)->value > (*sa)->next->next->value)
	{
		rotate(sa, "ra\n");
		if ((*sa)->value > (*sa)->next->value)
			swap(sa, "sa\n");
	}
	else if ((*sa)->next->value > (*sa)->value
		&& (*sa)->next->value > (*sa)->next->next->value)
	{
		rrotate(sa, "rra\n");
		if ((*sa)->value > (*sa)->next->value)
			swap(sa, "sa\n");
	}
	else if ((*sa)->value > (*sa)->next->value)
		swap(sa, "sa\n");
}

void	sort_five(t_stack **sa, t_stack **sb)
{
	t_stack	*min_node;

	if (stack_size(*sa) == 5)
	{
		min_node = ft_min(*sa);
		while (min_node != *sa)
			rotate(sa, "ra\n");
		push_b(sa, sb, "pb\n");
	}
	min_node = ft_min(*sa);
	while (min_node != *sa)
		rotate(sa, "ra\n");
	push_b(sa, sb, "pb\n");
	sort_three(sa);
	push_a(sa, sb, "pa\n");
	if (stack_size(*sb) > 0)
		push_a(sa, sb, "pa\n");
}

int	chunk_size(int size)
{
	if (size <= 100)
		return (16);
	return (36);
}

int	ft_sort(t_stack **sa, t_stack **sb, int size)
{
	int	i;
	int	j;

	i = 0;
	j = chunk_size(size);
	while ((*sa))
	{
		if ((*sa)->index <= i)
		{
			push_b(sa, sb, "pb\n");
			i++;
		}
		else if ((*sa)->index <= i + j)
		{
			push_b(sa, sb, "pb\n");
			rotate(sb, "rb\n");
			i++;
		}
		else if (reverse_sorted(*sa))
			rrotate(sa, "rra\n");
		else
			rotate(sa, "ra\n");
	}
	return (ft_push(sa, sb), 0);
}

void	ft_push(t_stack **sa, t_stack **sb)
{
	while ((*sb))
	{
		ft_position(sb);
		if (*sb == ft_max(*sb))
			push_a(sa, sb, "pa\n");
		else if (ft_max(*sb)->position <= stack_size(*sb) / 2)
			rotate(sb, "rb\n");
		else
			rrotate(sb, "rrb\n");
	}
}
