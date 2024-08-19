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
	@printf "${GREEN}[LIBFT]Compiling...${NC}\n"
	@${CRLIB} ${NAME} ${OBJS}
	@printf "${GREEN}[LIBFT]Compiled Succesfully!${NC}\n"

clean:
	@rm -f ${OBJS}
	@printf "${GREEN}[LIBFT]Clean Completed.${NC}\n"

fclean: clean
	@rm -f ${NAME} ${OBJS}
	@printf "${GREEN}[LIBFT]Full Clean Completed.${NC}\n"

re: fclean all

.PHONY: all clean fclean re
