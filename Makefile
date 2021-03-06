# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 16:14:13 by yoelguer          #+#    #+#              #
#    Updated: 2020/02/22 15:55:05 by yoelguer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= 	main.c mandelbrot.c hook.c julia.c julias.c astro.c clear_and_draw.c

OBJ		= $(SRC:.c=.o)

NAME 	= fractol

CFLAGS = -Wall -Wextra -Werror

FLAG	= -lmlx -framework OpenGL -framework AppKit

CC = @gcc

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft/
	@gcc $(OBJ) $(FLAG) libft/libft.a -o $(NAME)
	@echo "\033[92mDone for fractol\033[0m"

clean :
	@make clean -C ./libft/
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)

norme:
	@norminette $(SRC)

re : fclean all
