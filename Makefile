NAME = so_long
CC = cc
CFLAGS	:= -Wextra -Wall -Werror -g -Wunreachable-code
LIBMLX	:= ./lib/MLX42
MLX_REPO := https://github.com/codam-coding-college/MLX42.git
LIBFT   := ./lib/libft
LIBFT_REPO := git@github.com:AnselmiVeikko/Libft.git 

HEADERS	:= -I ./include -I $(LIBMLX)/include/MLX42 -I $(LIBFT)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a
SRCS	:= ./src/utils.c \
	   ./src/parse_map.c \
	   ./src/so_long.c \
	   ./src/init_game.c \
	   ./src/init_utils.c \
	   ./src/move_hooks.c \
	   ./src/render_game.c \
	   ./src/check_map.c \

OBJS	:= ${SRCS:.c=.o}

YELLOW := \033[0;33m
RED    = \033[0;31m
NC := \033[0m

all: libmlx libft $(NAME)

mkd_lib:
	@if [ ! -d ./lib ]; then \
		mkdir lib; \
		printf "$(YELLOW)[Directory]: Lib has been created.$(NC)\n"; \
	fi

clone_mlx: mkd_lib
	@if [ ! -d $(LIBMLX) ]; then \
		git clone $(MLX_REPO) $(LIBMLX); \
	fi

clone_libft: mkd_lib
	@if [ ! -d $(LIBFT) ]; then \
		git clone $(LIBFT_REPO) $(LIBFT); \
	fi

libmlx: clone_mlx
	@if [ ! -f $(LIBMLX)/build/libmlx42.a ]; then \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 ; \
	fi

libft: clone_libft
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
	@rm -rf ./lib
	@printf "$(RED)[Directory]: ./lib/MLX42 has been removed.$(NC)\n"
	@printf "$(RED)[Directory]: ./lib/Libft has been removed.$(NC)\n"
	@printf "$(YELLOW)[Directory]: Lib has been removed.$(NC)\n"

re: clean all

.PHONY: all clean fclean re libmlx libft
