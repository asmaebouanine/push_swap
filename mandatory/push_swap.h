/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:25:24 by asbouani          #+#    #+#             */
/*   Updated: 2025/03/19 12:12:50 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_max(t_stack *stack);
t_stack	*ft_min(t_stack *stack);
t_stack	*ft_stack_new(int value);
t_stack	*ft_last(t_stack *stack);
void	ft_position(t_stack **stack);
void	ft_index(t_stack *stack);
void	ft_add_front(t_stack **stack, t_stack *new);
void	ft_add_back(t_stack **stack, t_stack **new);
void	swap(t_stack **stack, char *str);
void	ss(t_stack **sa, t_stack **sb);
void	push_a(t_stack **sa, t_stack **sb, char *str);
void	push_b(t_stack **sa, t_stack **sb, char *str);
void	rotate(t_stack **stack, char *str);
void	rr(t_stack **sa, t_stack **sb);
void	rrotate(t_stack **stack, char *str);
void	rrr(t_stack **sa, t_stack **sb);
void	sort_three(t_stack **sa);
void	sort_five(t_stack **sa, t_stack **sb);
void	ft_push(t_stack **sa, t_stack **sb);
char	**ft_split(char const *s, char c);
int		ft_sort(t_stack **sa, t_stack **sb, int size);
int		stack_size(t_stack *stack);
int		ft_error(char *str);
int		ft_strlen(char *str);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		main(int ac, char **av);
int		max_positon(t_stack **stack);
int		is_sorted(t_stack *stack);
int		reverse_sorted(t_stack *a);

#endif
