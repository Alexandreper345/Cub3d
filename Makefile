NAME = Cub3d
CC = cc
CFLAGS = -g -O0 -Wall -Wextra -Werror
RM = rm -rf

# ==========================
#       SOURCE FILES
# ==========================

# Arquivos dentro de src/
SRC = \
	src/gameplay/game.c \
	src/gameplay/hooks.c \
	src/gameplay/gameplay.c \
	src/gameplay/gameplay_utils.c \
	src/gameplay/render_map.c \
	src/gameplay/walk_hook.c \
	src/gameplay/dda.c \
	src/parsing/vars_init.c \
	src/parsing/check_file.c \
	src/parsing/parsing.c \
	src/parsing/recreate_matriz.c \
	src/parsing/init_matriz.c \
	src/parsing/flood_fill.c \
	src/parsing/get_path_texture.c \
	src/parsing/validate_map.c \
	src/parsing/check_two_map.c \
	src/error/ft_error.c \
	src/free/free_mlx.c \
	src/utils.c 

# Arquivos raíz
MAIN_SRC = main.c

# GNL
GNL_SRC = \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# ==========================
#       OBJECT FILES
# ==========================

OBJ = $(SRC:.c=.o) \
	  $(MAIN_SRC:.c=.o) \
	  $(GNL_SRC:.c=.o)

# ==========================
#        RULES
# ==========================

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) \
		-Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz \
		-o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
