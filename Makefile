CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
X11FLAGS =  -L/usr/local/lib -lmlx -L/usr/X11/lib -lXext -lX11
RM = rm -f
INC = -I./include
SRCS_DIR = ./printf
GNL_DIR = ./gnl
FILES = ${SRCS_DIR}/ft_printf.c ${SRCS_DIR}/put_char.c \
			${SRCS_DIR}/put_string.c ${SRCS_DIR}/put_pointerall.c \
			${SRCS_DIR}/put_integer.c ${SRCS_DIR}/put_unsigint.c \
			${SRCS_DIR}/put_hex.c ${GNL_DIR}/get_next_line_utils.c \
			${GNL_DIR}/get_next_line.c  main.c handle_resources.c \
			map_checker.c render_map.c colision_checker.c \
			win_death.c
OBJS = ${FILES:.c=.o}
NAME = so_long

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INC} -c $< -o $@ 

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${INC} -o ${NAME} ${X11FLAGS}


bonus: all

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re