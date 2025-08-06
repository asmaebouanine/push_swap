/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:24:10 by asbouani          #+#    #+#             */
/*   Updated: 2025/03/15 15:12:31 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

typedef struct s_stack
{
	int				value;
	char			*op;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(char *op);
t_stack	*ft_stack_new(int value);
t_stack	*ft_last(t_stack *stack);
void	ft_clear(t_stack *stack);
void	ft_free2(char **stack);
void	ft_add_front(t_stack **stack, t_stack *new);
void	ft_add_back(t_stack **stack, t_stack *new);
void	swap(t_stack **stack, char *str);
void	ss(t_stack **sa, t_stack **sb);
void	push_a(t_stack **sa, t_stack **sb, char *str);
void	push_b(t_stack **sa, t_stack **sb, char *str);
void	rotate(t_stack **stack, char *str);
void	rr(t_stack **sa, t_stack **sb);
void	rrotate(t_stack **stack, char *str);
void	rrr(t_stack **sa, t_stack **sb);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *str, int c);
char	*ft_read_file(int fd, char *str);
long	ft_atoi(const char *str);
int		ft_error(char *str);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		main(int ac, char **av);
int		is_sorted(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);
int		check_sort(t_stack **a, t_stack **b);

#endif