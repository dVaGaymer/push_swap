# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 22:01:15 by alopez-g          #+#    #+#              #
#    Updated: 2022/07/07 02:27:16 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
CYAN = \033[0;36m
GREEN = \033[1;32m
YELLOW = \033[1;33m
NC = \033[0m

DIR = .
NAME = $(DIR)/push_swap

FTPF_DIR = $(DIR)/src/ft_printf
LIBFT_DIR = $(FTPF_DIR)/srcs/Libft
FTPF_LIB = ftprintf
FTPF_A = $(FTPF_DIR)/lib$(FTPF_LIB).a

FTPF_SRC_DIR = $(DIR)/src/ft_printf/srcs
FTPF_SRC = $(wildcard $(FTPF_SRC_DIR)/*.c)
LIBFT_SRC_DIR = $(DIR)/src/ft_printf/srcs/Libft/srcs
LIBFT_SRC = $(wildcard $(LIBFT_SRC_DIR)/*.c)

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
	@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@

all: $(NAME)
$(NAME): $(FTPF_SRC) $(LIBFT_SRC) $(OBJ) $(I)
	@echo "${RED}Compiling LIBFTPRINTF${NC}\c"
	@make -s -C $(FTPF_DIR)
	@echo " ---> ${CYAN}Success${NC}"
	@$(CC) $(FLAGS) $(OBJ) -L$(FTPF_DIR) -l$(FTPF_LIB) -o push_swap
	@echo "${GREEN}${NAME} READY!${NC}"
clean:
	@make -s -C $(FTPF_DIR) clean
	@rm -rf $(OBJ)
	@echo "${YELLOW}OBJS Removed!${NC}"
fclean: clean
	@make -s -C $(FTPF_DIR) fclean
	@rm -rf $(NAME)
	@echo "${YELLOW}$(NAME) Removed!${NC}"
re: fclean $(NAME)
pls: FLAGS = -g
pls: re
.PHONY: clean fclean re

