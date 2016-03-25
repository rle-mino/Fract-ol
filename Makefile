# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 11:31:38 by rle-mino          #+#    #+#              #
#    Updated: 2016/03/24 17:11:39 by rle-mino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME
NAME	=	fractol

#SOURCE
SRC		=	main.c			\
			frac_err.c		\
			fracolors.c		\
			mandel.c		\
			mand_hook.c		\
			zoom.c			\
			opencl_init.c	\
			mandelbrot.c

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
	@printf "\033[1;37mCompiling\033[0m fractol"
	@gcc $(DOTO) -lft -L ./libft -lmlx -Iincludes -framework OpenGL -framework AppKit -framework OpenCL -o $(NAME)
	@printf "\t[\033[0;36mSUCCESS\033[0m]\n"

%.o: %.c
	@gcc -c $(FLAGS) -I includes $< -o $@

clean:
	@rm -rf $(DOTO)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)
