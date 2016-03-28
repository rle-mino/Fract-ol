# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 11:31:38 by rle-mino          #+#    #+#              #
#    Updated: 2016/03/28 22:31:14 by rle-mino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME
NAME	=	fractol

#SOURCE
SRC		=	main.c			\
			frac_err.c		\
			fracolors.c		\
			mandel.c		\
			julia.c			\
			burningship.c	\
			celtic.c		\
			druid.c			\
			hook.c			\
			zoom.c			\
			opencl_init.c	\
			frac_get.c		\
			frac_exit.c		\
			fractal.c

DOTO	=	$(SRC:.c=.o)


#FLAGS
FLAGS	= -Wall -Wextra -Werror

#RULES

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(DOTO)
	@make -C libft/
	@gcc $(DOTO) -lft -L ./libft -lmlx -Iincludes -framework OpenGL -framework AppKit -framework OpenCL -o $(NAME)
	@echo "compiling" $(NAME)

%.o: %.c
	gcc -c $(FLAGS) -I includes $< -o $@

clean:
	make -C libft fclean
	rm -rf $(DOTO)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
