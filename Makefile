# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 18:36:41 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/24 15:22:39 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=push_swap

BONUS:=checker

SRC_DIR:=srcs
SRCS:=main.c parse_input.c parse_int.c utils1.c \
	stack.c op_swap.c op_push.c op_rotate.c op_r_rotate.c \
	merge_main.c merge_init.c merge_merge.c tiny_sort.c
BSRCS:= main_bonus.c parse_input.c parse_int.c get_next_line_bonus.c \
	op_swap.c op_push.c op_rotate.c op_r_rotate.c \
	stack.c utils1.c

INC_DIR:=incs
INCS:=push_swap.h utils.h

LIBFT:=ft
LIBFT_DIR:=libft

CC:=cc
CFLAGS:=-Wall -Wextra -Werror

$(NAME) : $(addprefix $(SRC_DIR)/, $(SRCS)) $(addprefix $(INC_DIR)/, $(INCS))
	@make -sC $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $(addprefix $(SRC_DIR)/, $(SRCS)) -I $(INC_DIR) \
	-I $(LIBFT_DIR) -L $(LIBFT_DIR) -l$(LIBFT)

$(BONUS) : $(addprefix $(SRC_DIR)/, $(BSRCS)) $(addprefix $(INC_DIR)/, $(INCS))
	@make -sC $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $(addprefix $(SRC_DIR)/, $(BSRCS)) -I $(INC_DIR) \
	-I $(LIBFT_DIR) -L $(LIBFT_DIR) -l$(LIBFT)

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) fclean

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all

bonus : $(BONUS)
