# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 15:16:27 by yohatana          #+#    #+#              #
#    Updated: 2024/11/25 21:32:52 by yohatana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME		= push_swap

# src files
SRCS		=\
				main.c\
				init.c\
				push_swap.c\
				command.c\
				ft_atoi_ps.c\
				stack_move_a.c\
				stack_move_b.c\
				sort.c\
				get_num.c\
				stack_move_both.c\
				error.c\
				push_swap_helper.c

# object file name
OBJS		= $(SRCS:.c=.o)
%o: %c
		$(CC) $(CCFLAGS) -I$(PRINTF) -c $< -o $@

# compile flag
CC			= cc
CCFLAGS		= -Wall -Wextra -Werror

# Archive and remove command
AR			= ar rcs
RM			= rm -f

all:		$(NAME)

# libft
LIBFT = libft
$(LIBFT)/libft.a:
		make -C $(LIBFT)

# printf
PRINTF = printf
$(PRINTF)/libftprintf.a:
		make -C $(PRINTF)

${NAME}:	${OBJS}  $(PRINTF)/libftprintf.a $(LIBFT)/libft.a
			$(CC) ${OBJS} -L$(LIBFT) -lft -L$(PRINTF) -lftprintf -o $(NAME)

clean:
			make -C $(PRINTF) clean
			make -C $(LIBFT) clean
			${RM} $(OBJS)

fclean:		clean
			make -C $(LIBFT) fclean
			make -C $(PRINTF) fclean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
