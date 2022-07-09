# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 18:36:41 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/09 23:01:03 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=push_swap

SRCS:=main.c init_stack.c parse_int.c\
	stack.c stack_swap.c stack_push.c stack_rotate.c stack_reverse_rotate.c

INCS:=stack.h push_swap.h

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

fclean :
	rm -f $(NAME)

re : fclean all
