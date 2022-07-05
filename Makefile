# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 22:01:15 by alopez-g          #+#    #+#              #
#    Updated: 2022/07/05 23:49:37 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR = .
NAME = $(DIR)/push_swap

FTPF_DIR = $(DIR)/src/ft_printf
LIBFT_DIR = $(FTPF_DIR)/srcs/Libft
FTPF_LIB = ftprintf
FTPF_A = $(FTPF_DIR)/lib$(FTPF_LIB).a

I_FTPF = $(FTPF_DIR)/includes
I_FTPF_H = $(I_FTPF)ftpritf.h

I_LIBFT = $(LIBFT_DIR)/includes
I_LIBFT_H = $(I_LIBT)/libft.h

I_DIR = $(DIR)/includes
I_H = push_swap.h
I = $(patsubst %.h, $(I_DIR)/%.h, $(I_H))

SRC_DIR = $(DIR)/src
SRC_C = main.c
SRC = $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_C))

OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc
FLAGS = -Wall -Wextra -Werror
I_FLAG = -I $(I_DIR)/ -I $(I_FTPF)/ -I $(I_LIBFT)/
%.o : %.c
	$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@

all: $(NAME)
$(NAME): $(OBJ) $(I)
	make -C $(FTPF_DIR)
	$(CC) $(FLAGS) $(OBJ) -L$(FTPF_DIR) -l$(FTPF_LIB) -o push_swap
clean:
	make -C $(FTPF_DIR) clean
	rm -rf $(OBJ)
fclean: clean
	make -C $(FTPF_DIR) fclean
	rm -rf $(NAME)
re: fclean $(NAME)
pls: FLAGS = -g
pls: $(NAME)
.PHONY: clean fclean re

