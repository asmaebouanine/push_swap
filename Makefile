# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 16:27:14 by asbouani          #+#    #+#              #
#    Updated: 2025/03/18 23:11:57 by asbouani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory/push_swap.c mandatory/ft_operation.c mandatory/ft_operation_1.c mandatory/ft_sort.c \
	   mandatory/ft_split.c mandatory/ft_utils.c mandatory/ft_stack.c mandatory/ft_utils_1.c
BSRCS = bonus/push_swap_bonus.c bonus/ft_operation_bonus.c bonus/ft_operation1_bonus.c bonus/ft_checker_bonus.c \
		bonus/ft_split_bonus.c bonus/ft_utils_bonus.c bonus/ft_stack_bonus.c bonus/get_next_line_bonus.c \
		bonus/get_next_line_utils_bonus.c
OBJS = ${SRCS:.c=.o}
BOBJS = ${BSRCS:.c=.o}
HEADER = mandatory/push_swap.h
HEADER_B = bonus/push_swap_bonus.h

all: ${NAME}

mandatory/%.o: mandatory/%.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

bonus/%.o: bonus/%.c ${HEADER_B}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} 
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus : ${BOBJS} 
	${CC} ${CFLAGS} ${BOBJS} -o ${BONUS}

clean:
	rm -f ${OBJS} ${BOBJS}


fclean: clean
	rm -f ${NAME} ${BONUS}


re: fclean all

.PHONY: clean