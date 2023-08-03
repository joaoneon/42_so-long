# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 18:14:45 by jpedro-a          #+#    #+#              #
#    Updated: 2023/08/03 18:22:10 by jpedro-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
X11FLAGS = -lmlx -lXext -lX11
RM = rm -f
INC = -I./include
PRINT_DIR = ./printf
GNL_DIR = ./gnl
SRCS_DIR = ./srcs
FILES = ${PRINT_DIR}/ft_printf.c ${PRINT_DIR}/put_char.c \
			${PRINT_DIR}/put_string.c ${PRINT_DIR}/put_pointerall.c \
			${PRINT_DIR}/put_integer.c ${PRINT_DIR}/put_unsigint.c \
			${PRINT_DIR}/put_hex.c ${GNL_DIR}/get_next_line_utils.c \
			${GNL_DIR}/get_next_line.c main.c ${SRCS_DIR}/win_death.c \
			${SRCS_DIR}/handle_resources.c \
			${SRCS_DIR}/colision_aux.c ${SRCS_DIR}/colision_checker.c \
			${SRCS_DIR}/copy_map.c ${SRCS_DIR}/free_aux.c \
			${SRCS_DIR}/load_images.c ${SRCS_DIR}/map_checker.c \
			${SRCS_DIR}/map_checker2.c ${SRCS_DIR}/movement_aux.c \
			${SRCS_DIR}/program_flux.c ${SRCS_DIR}/put_map.c \
			${SRCS_DIR}/render_map.c ${SRCS_DIR}/some_resources.c \
			  

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