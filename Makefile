# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 22:01:15 by alopez-g          #+#    #+#              #
#    Updated: 2022/07/05 22:17:13 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR = .
NAME = $(DIR)/push_swap

I_DIR = $(DIR)/includes
I_NAMES = push_swap.h
I = $(patsubst %.h, $(I_DIR)/%.h, $(I_NAMES))

SRC_DIR = $(DIR)/src
SRC_NAMES = main.c
SRC = $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_NAMES))

OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc
FLAGS = -Wall -Wextra -Werror
I_FLAG = -I $(I_DIR)/
%.o : %.c
	$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@

all: $(NAME)
$(NAME): $(OBJ) $(I)
	$(CC) $(FLAGS) $(OBJ) -o push_swap
clean:
	rm $(OBJ)
fclean: clean
	rm $(NAME)
re: fclean $(NAME)
.PHONY: clean fclean re

