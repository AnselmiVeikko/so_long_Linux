# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 16:46:51 by ahentton          #+#    #+#              #
#    Updated: 2024/08/07 16:50:43 by ahentton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CRLIB = ar rcs

SRC = initmlx \

SRCS = $(addsuffix .c, ${SRC})
OBJ_DIR = obj
OBJS = $(addprefix  ${OBJ_DIR}/, ${SRCS:.c=.o})

${OBJ_DIR}/%.o: %.c | ${OBJ_DIR}
	${CC} ${CFLAGS} -c $< -o $@ $@ $(INCLUDES)

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES = -I/opt/X11/include -Imlx
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib /lXext /lX11 -framework openGL -framework AppKit
endif

MLX_PATH  = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a

LIBFT_PATH = ./libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a



all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_PATH)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

clean:
	make -C ${MLX_PATH} clean
	make -C ${LIBFT_PATH} clean
	rm -rf ${OBJ_DIR}

fclean: clean
	make -C ${MLX_PATH} fclean
	make -C ${LIBFT_PATH} fclean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
