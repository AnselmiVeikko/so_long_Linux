NAME = so_long
CC = cc
CFLAGS	:= -Wextra -Wall -Werror -g -Wunreachable-code
LIBMLX	:= ./lib/MLX42
MLX_REPO := https://github.com/codam-coding-college/MLX42.git
LIBFT   := ./lib/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include/MLX42 -I $(LIBFT)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

$(LIBMLX):
	@git clone $(MLX_REPO) $(LIBMLX)

libmlx:
	@cmake -S $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -- -j4 

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: clean all

.PHONY: all clean fclean re libmlx libft
