# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 15:15:38 by paranha           #+#    #+#              #
#    Updated: 2024/03/19 18:55:30 by paranha          ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

RED		=	\033[0;31m
GRN		=	\033[0;32m
YLW		=	\033[0;33m
BLU		=	\033[0;34m
MAG		=	\033[0;35m
CYA		=	\033[0;36m
WHT		=	\033[0;37m
RST		=	\033[0m

NAME	=	so_long

FILES	=	main.c cleaning.c validations.c \
		flood_fill.c images.c map.c \
		moves.c

BONUS	=	main_bonus.c animations_bonus.c cleaning_bonus.c \
		validations_bonus.c flood_fill_bonus.c images_bonus.c \
		map_bonus.c moves_bonus.c events_bonus.c renders_bonus.c
		
SRCDIR	=	src_mandatory
BNSDIR	=	src_bonus
SRC		=	$(FILES:%.c=$(SRCDIR)%.o)
SRCBNS =	$(FILES:%.c=$(BNSDIR)%.o)

OBJDIR	=	obj
OBJ		=	${FILES:%.c=$(OBJDIR)/%.o}
OBJ_BNS	=	$(BONUS:%.c=$(OBJDIR)/%.o)

CC		=	cc
CFLGS	=	-Wextra -Wall -Werror
MLXFLGS	=	-ldl -lglfw -pthread -lm -Ofast

LIBFT	=	./libs/libft
FT_PRINTF	=	./libs/ft_printf
LIBMLX	=	./libs/MLX42

INCLUDE	=	-I ./inc -I $(LIBFT) -I $(FT_PRINTF) -I $(LIBMLX)/include
LIBS	=	$(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(LIBMLX)/build/libmlx42.a

DEL		=	$(OBJ_BNS)

ifdef WITH_BONUS
	DEL		:=	$(OBJ)
	SRCDIR	:=	$(BNSDIR)
	OBJ		:=	$(OBJ_BNS)
endif

all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	rm -rf $(DEL)
	$(CC) $(CFLGS) $(OBJ) $(LIBS) $(INCLUDE) $(MLXFLGS) -ldl -lglfw -pthread -lm -Ofast -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLGS) $(INCLUDE) -c $< -o $@
	@echo "${GRN}Compile $@ DONE${RST}"

$(LIBS):
	@make -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

bonus:
	@make WITH_BONUS=TRUE --no-print-directory

clean:
	@rm -rf $(OBJDIR)
	@echo "${RED}CLEAN:	Objects $(OBJ) DELETED${RST}"

fclean: clean
	@make fclean -sC $(LIBFT)
	@echo "${RED}CLEAN:	Lib $(LIBFT) DELETED${RST}"
	@make fclean -sC $(FT_PRINTF)
	@echo "${RED}CLEAN:	Lib $(FT_PRINTF) DELETED${RST}"
	@rm -rf $(LIBMLX)/build
	@echo "${RED}CLEAN:	Lib $(LIBMLX) DELETED${RST}"
	@rm -rf $(NAME)
	@echo "${RED}FCLEAN $(NAME) DELETED${RST}"

re: clean all

.PHONY: all, bonus, clean, fclean, re
