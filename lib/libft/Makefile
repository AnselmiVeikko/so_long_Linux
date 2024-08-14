# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 12:42:55 by ahentton          #+#    #+#              #
#    Updated: 2024/05/06 13:59:49 by ahentton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror ${HEADERS} -fPIC
CRLIB = ar rcs

SRCS := $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}
HEADERS	:= -I ./include

GREEN := \033[0;32m
NC := \033[0m


all: ${NAME}

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $<

${NAME} : ${OBJS}
	@echo -e "${GREEN}[LIBFT]Compiling...${NC}"
	@${CRLIB} ${NAME} ${OBJS}
	@echo -e "${GREEN}[LIBFT]Compiled Succesfully!${NC}"

clean:
	@rm -f ${OBJS}
	@echo -e "${GREEN}[LIBFT]Clean Completed.${NC}"

fclean: clean
	@rm -f ${NAME} ${OBJS}
	@echo -e "${GREEN}[LIBFT]Full Clean Completed.${NC}."

re: fclean all

.PHONY: all clean fclean re
