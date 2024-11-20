# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 18:39:58 by paranha           #+#    #+#              #
#    Updated: 2024/01/24 16:19:02 by paranha          ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a


SRCS	=		ft_printf.c			\
			ft_printf_func.c		\
			ft_printf_int.c			\

SRCS_BONUS =		ft_printf_bonus.c		\
			ft_printf_func_bonus.c		\
			ft_printf_int_bonus.c		\

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

DEL_SRCS = $(OBJS_BONUS)
DEL_LIB = $(SRCS_BONUS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	DEL_SRCS := $(OBJS)
	OBJS = $(OBJS_BONUS)
	DEL_LIB = $(SRCS:%.c=%.o)
endif

all: $(NAME)

$(NAME): $(OBJS)
	rm -rf $(DEL_SRCS)
	ar -d $(NAME) $(DEL_LIB)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar -rcs $(NAME) $@

bonus:
	@make WITH_BONUS=TRUE --no-print-directory

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
