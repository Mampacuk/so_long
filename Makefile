# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 13:23:26 by aisraely          #+#    #+#              #
#    Updated: 2021/07/10 13:23:27 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
SRCS = $(wildcard *.c)
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -O3 -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

${NAME}: ${OBJS}
	@echo [so_long] Compiling mlx...
	@$(MAKE) -C ./mlx
	@echo [so_long] Compiling Libft...
	@$(MAKE) -C ./libft
	@mv mlx/libmlx.dylib .
	@echo [so_long] Compiling cub3D...
	@${CC} ${OBJS} ${CFLAGS} ${MLX} ./libft/libft.a libmlx.dylib -o ${NAME}
	@echo [so_long] so_long successfully compiled. Run ./so_long \*.ber to read from a map. 

clean:
	@$(MAKE) -C mlx clean
	@$(MAKE) -C libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} libmlx.dylib

norme:
	@norminette -R CheckForbiddenSourceHeader *.c *.h libft/*.c libft/*.h
	
bonus: all

re: fclean all

.PHONY: clean fclean re all bonus
