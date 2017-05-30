# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 09:43:24 by bzmuda            #+#    #+#              #
#    Updated: 2017/05/30 09:43:36 by bzmuda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Library
NAME = 				libft.a 

# 	Compiler 
CC = 				gcc

#	Flags for norme + LLDB
CFLAGS = 			-Wall -Wextra -Werror -g

#	Headers infos
HEA_PATH = 			.
HEA_NAME = 			libft.h
HEA = 				$(addprefix $(HEA_PATH)/,$(HEA_NAME))

#	Sources infos
SRC_PATH = 			.
SRC_NAME = 			$(shell ls | grep -E "ft_.+\.c") \
					get_next_line.c
SRC = 				$(addprefix $(SRC_PATH)/,$(SRC_NAME))		

#	Objects infos
OBJ_PATH = 			.
OBJ_NAME = 			$(SRC_NAME:.c=.o)
OBJ = 				$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


###############################################################################


all: $(NAME)

$(NAME): 			$(OBJ) 
					@ar rc $(NAME) $(OBJ)
					@ranlib $(NAME)
					@echo "Libft compilation complete."

%.o: 				%.c $(HEA)
					@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
					@rm -rf $(OBJ)
					@echo "Object files deleted." 

fclean: 			clean
					@rm -rf $(NAME) 
					@echo "Executable deleted." 

re: 				fclean all

.PHONY: 			all clean fclean re


###############################################################################
