# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 14:26:42 by aminewalial       #+#    #+#              #
#    Updated: 2020/02/10 22:52:44 by awali-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

FLAGS = -g -Wall -Wextra -Werror

SRC_DIR = src

SRC_FILES =  to_sh.c envirenement.c display.c get_line.c term_set.c \
edit_in_pos.c cursor.c navigation.c extra.c up_down.c history.c \
new_line.c curmove.c

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ_DIR = .obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIB = libft/libft.a

HEADER = includes/to_sh.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	make -C libft/
	gcc $(FLAGS) -I $(HEADER) $(OBJ) $(LIB) -o $(NAME) -ltermcap
	# clear

$(OBJ) : $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc $(FLAGS) -c $< -I $(HEADER) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	
clean :
	make -C libft/ clean
	/bin/rm -rf $(OBJ_DIR)

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re : fclean all
