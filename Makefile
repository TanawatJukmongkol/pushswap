# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 06:32:57 by tjukmong          #+#    #+#              #
#    Updated: 2023/05/04 16:38:47 by tjukmong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRCS		= push_swap.c utils.c utils2.c stack.c stack2.c parser.c instruct.c\
				radix_sort.c small_sort.c

SRC_DIR		= ./src/
LIB_DIR		= ./lib/
BUILD_DIR	= ./build/

SRC			= ${addprefix ${BUILD_DIR},${SRCS}}
OBJ			= ${SRC:.c=.o}

CC			= gcc
CFLAG		= -g -Wall -Werror -Wextra -O3

all: library ${BUILD_DIR} ${NAME}

library:
	find ${LIB_DIR} -mindepth 1 -maxdepth 1 -exec make -C {} \;

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ${NAME}

re: fclean all

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

${BUILD_DIR}%.o:${SRC_DIR}%.c
	$(CC) $(CFLAG) -c -o $@ $^

${NAME}: ${OBJ}
	$(CC) ${OBJ} ${wildcard ${LIB_DIR}/*/*.a} -o ${NAME} $(CFLAG)

.PHONY:	all library clean fclean re
