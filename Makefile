# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 14:35:30 by ayguillo          #+#    #+#              #
#    Updated: 2019/04/26 10:43:41 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRC = srcs/main.c srcs/parsing.c srcs/tools.c srcs/bresenham.c srcs/hook.c \
	  srcs/matrix.c
LIB = libft/libft.a
YELLOW = \033[0;33m
RED = \033[0;31m
GREEN = \033[0;32m
WHITE = \x1b[0m

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	@ echo "$(YELLOW)Compilation de $(NAME). . .$(WHITE)"
	@ gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
	@ echo "$(GREEN)$(NAME) compilé$(WHITE)"

$.o : %.c lemin.h
	@ gcc $(FLAGS) -c $< 

$(LIB) :
	@ make -C libft

clean :
	@ rm $(OBJ)
	@ make clean -C libft
	@ echo "$(RED)Suppression des .o$(WHITE)"

fclean : clean
	@ rm $(LIB)
	@ rm $(NAME)
	@ echo "$(RED)Suppression de $(NAME)$(WHITE)"

re : fclean all

.PHONY : clean fclean re all
