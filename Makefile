NAME = Cub3d
CC = cc -g
FLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux
RM = rm -rf
SRCC_GNL = get_next_line.c get_next_line_utils.c
SRCC_MAIN = main.c \
			game.c \
			vars_init.c \

SRCC =  parsing/parsing.c error/ft_error.c
SRC_DIR_SRC = src/
SRC_DIR_GNL = get_next_line/
LIBFT_DIR=libft
LIBFT=$(LIBFT_DIR)/libft.a

SRC = $(addprefix $(SRC_DIR_SRC), $(SRCC))
SRC_GNL = $(addprefix $(SRC_DIR_GNL), $(SRCC_GNL))
OBJS_MAIN = $(SRCC_MAIN:.c=.o)
OBJS_SRC = $(SRC:.c=.o)
OBJS_GNL = $(SRC_GNL:.c=.o)

all: $(NAME)

${NAME} : ${OBJS_MAIN} ${OBJS_GNL} ${OBJS_SRC} ${LIBFT_DIR}
	@make -C ${LIBFT_DIR}
	$(CC) $(FLAGS) $(OBJS_MAIN) $(OBJS_GNL) $(OBJS_SRC) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	${RM} ${OBJS_MAIN}  
	${RM} ${OBJS_GNL}
	${RM} ${OBJS_SRC}

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	${RM} ${NAME}

re: fclean all