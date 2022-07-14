# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 18:36:41 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/14 13:46:16 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=push_swap

SRCS:=main.c parse_input.c parse_int.c \
	stack.c stack2.c stack_util.c \
	operate.c op_swap.c op_push.c op_rotate.c op_r_rotate.c \
	quick_sort.c

INCS:=stack.h operate.h

LIBFT:=ft
LIBFT_DIR:=libft

CC:=cc
CFLAGS:=-Wall -Wextra -Werror

$(NAME) : $(SRCS) $(INCS)
	@make -sC $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $(SRCS) \
	-I $(LIBFT_DIR) -L $(LIBFT_DIR) -l$(LIBFT)

.PHONY : all clean fclean re

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) fclean

fclean : clean
	rm -f $(NAME)

re : fclean all
