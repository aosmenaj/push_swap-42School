# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 18:27:47 by aosmenaj          #+#    #+#              #
#    Updated: 2025/05/13 11:42:14 by aosmenaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	check_how_many.c check_sort_type.c fill_node.c ft_back_to_a.c \
				ft_exit.c ft_find_cheapest_a.c ft_find_cheapest_b.c ft_find_max_nb.c ft_find_target_in_a.c \
				ft_find_target_in_b.c ft_free_stack.c ft_last_check.c ft_push_in_a.c \
				ft_push_in_b.c full_sort.c last_node.c push_swap.c not_sorted.c push.c pute_node.c \
				repeat_contr.c reverse_rotate.c rotate.c sort_three.c swap.c ft_check_if_valid.c myatoi.c

OBJS		=$(SRC:.c=.o)

BONUS		=	ft_check_if_valid_bonus.c pute_node_bonus.c myatoi_bonus.c ft_exit_bonus.c \
				checker.c read_exec_moves.c get_next_line.c get_next_line_utils.c \
				push_bonus.c reverse_rotate_bonus.c rotate_bonus.c swap_bonus.c

BONUS_OBJS	= $(BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -g -Werror -Wall -Wextra

NAME			= push_swap
BONUS_NAME		= checker

all:		$(NAME) $(BONUS_NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS_NAME):	$(BONUS_OBJS)
			$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:		
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
			$(RM) $(NAME) $(BONUS_NAME)

re:			fclean all

.PHONY:		all clean fclean re
