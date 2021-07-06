NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)libft.a
LIBMLX_DIR = ./mlx
LIBMLX = $(LIBMLX_DIR)libmlx.dylib
MAKE = make
CLEAN = clean
FCLEAN = fclean
SRC = get_next_line.c ft_mlx_utils1.c ft_mlx_utils2.c so_long.c ft_render.c ft_parser.c ft_parser_utils1.c ft_parser_utils2.c ft_check.c ft_loadtextures.c ft_receiveinput.c ft_events.c
OBJ = $(SRC:.c=.o)
CC = gcc
FLAG = -Wall -Werror -Wextra -g -O3
FLAGMLX = -framework OpenGL -framework AppKit
OPTION = -c -D GL_SILENCE_DEPRECATION
OPTIONOBJ = -o
DEL = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	@echo [so_long] Compiling Libft...
	@cd $(LIBFT_DIR) && mv ./libft.a ../
	@echo [so_long] Compiling mlx...
	@cd $(LIBMLX_DIR) && mv ./libmlx.dylib ../
	@echo [so_long] Compiling so_long...
	@$(CC) $(FLAG) $(OBJ) -L. -lmlx -lft $(FLAGSMLX) $(OPTIONOBJ) $(NAME)
	@echo [so_long] so_long successfully compiled. Run ./so_long \*.ber to read from a map.

$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKE)

$(LIBMLX):
	@cd $(LIBMLX_DIR) && $(MAKE)

%.o: %.c
	@$(CC) $(FLAG) $(OPTION) $< $(OPTIONOBJ) $@

clean:
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(CLEAN)
	@cd $(LIBMLX_DIR) && $(MAKE) $(CLEAN)
	
fclean: clean
	@$(DEL) $(NAME) ./libft.a ./libmlx.dylib
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(FCLEAN)

bonus: all
	
re: fclean all

.PHONY: all clean bonus fclean re