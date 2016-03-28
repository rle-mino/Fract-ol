# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 11:31:38 by rle-mino          #+#    #+#              #
#    Updated: 2016/03/28 02:56:46 by rle-mino         ###   ########.fr        #
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
			hook.c			\
			zoom.c			\
			opencl_init.c	\
			frac_get.c		\
			fractal.c

DOTO	=	$(SRC:.c=.o)


#COLOR
KCYN	=		"\033[0;36m"
KRESET	=		"\033[0m"
KRED	=		"\033[0;31m"
KWHI	=		"\033[1;37m"


#FLAGS
FLAGS	= -g3 -Wall -Wextra -Werror

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
	rm -rf $(DOTO)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
