# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 14:35:30 by ayguillo          #+#    #+#              #
#    Updated: 2019/05/21 11:52:10 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Wextra -Werror
SRC = srcs/main.c srcs/parsing.c srcs/tools.c srcs/bresenham.c srcs/hook.c \
	  srcs/matrix.c srcs/rotate.c srcs/color.c srcs/presentation.c \
	  srcs/colorearth.c srcs/print.c srcs/exit.c srcs/checknbr.c
LIB = libft/libft.a

YELLOW = \033[0;33m
RED = \033[0;31m
GREEN = \033[0;32m
WHITE = \x1b[0m

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	@ echo "$(YELLOW)Compilation de $(NAME). . .$(WHITE)"
	@ gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) -I /usr/local/include \
		-L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
	@ echo "$(GREEN)$(NAME) compilé$(WHITE)"

$.o : %.c lemin.h
	@ gcc $(CFLAGS) -c $< 

$(LIB) :
	@ make -C libft

clean :
	@ rm $(OBJ)
	@ make clean -C libft
	@ echo "$(RED)Suppression des .o$(WHITE)"

fclean : clean
	@ rm -f $(LIB)
	@ rm -rf $(NAME)
	@ echo "$(RED)Suppression de $(NAME)$(WHITE)"

re : fclean all

.PHONY : clean fclean re all
