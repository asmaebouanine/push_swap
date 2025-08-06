/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:46:53 by asbouani          #+#    #+#             */
/*   Updated: 2025/03/14 16:28:55 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack **stack, char *str)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (str)
		write (1, str, ft_strlen(str));
}

void	ss(t_stack **sa, t_stack **sb)
{
	swap(sa, NULL);
	swap(sb, NULL);
	write(1, "ss\n", 4);
}

void	push_a(t_stack **sa, t_stack **sb, char *str)
{
	t_stack	*tmp;

	if (!*sb)
		return ;
	tmp = *sb;
	*sb = (*sb)->next;
	tmp->next = NULL;
	ft_add_front(sa, tmp);
	if (str)
		write (1, str, ft_strlen(str));
}

void	push_b(t_stack **sa, t_stack **sb, char *str)
{
	t_stack	*tmp;

	if (!*sa)
		return ;
	tmp = *sa;
	(*sa) = (*sa)->next;
	tmp->next = NULL;
	ft_add_front(sb, tmp);
	if (str)
		write (1, str, ft_strlen(str));
}

t_stack	*stack_new(char *op)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->op = ft_strdup(op);
	new->next = NULL;
	return (new);
}
