# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 17:09:26 by jvasseur          #+#    #+#              #
#    Updated: 2023/01/18 15:53:42 by jvasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang -g

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC = parsing.c parsing_verif.c parsingtwo.c read_file.c so_long.c runmap_and_verif.c shift.c ft_utils.c

LIBFT = mlx_linux/libmlx.a -lXext -lX11 -lm -lz

MAKE = make -C

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(MAKE) mlx_linux
	$(MAKE) Libft
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) -LLibft -lft -LLibft/ft_printf -lftprintf
	
all : $(NAME)

clean :
	make -C Libft clean
	rm -f $(OBJ)

fclean : clean
	make -C Libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
