# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 07:15:06 by ahocuk            #+#    #+#              #
#    Updated: 2023/08/12 08:00:38 by ahocuk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
SRC =		./mapcheck.c \
			./utils.c \
			./bercheck.c \
			./ft_key.c \
			./ft_errorm.c \
			./so_long.c \
			./floodfl.c
LIBMLX		:= ./MLX42/
LIBFT		:= ./libft
OBJ			:= $(SRC:.c=.o)
OBJ_LIBFT   := ./libft/*.o
CC			:=	cc
CFLAGS		:= -Wall -Werror -Wextra
HEADERS		:= -Iinclude -lglfw

all: $(NAME) 

$(NAME): build_library $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a $(LINK_FLAGS) $(HEADERS) -o $(NAME)

build_library:
	@cmake -S $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build
	@make -C $(LIBFT)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_LIBFT)
	
fclean: clean
	@rm -f $(LIBFT)/libft.a 
	@rm -f ./so_long 
	
re: clean all

.PHONY: so_long,  all, clean, fclean, re, build_library








