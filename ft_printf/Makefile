# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:31:28 by juhaamid          #+#    #+#              #
#    Updated: 2022/11/17 10:47:25 by juhaamid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		numprint.c \
		printstr.c \
		hexprint.c \
		print_u.c \
		p_print.c

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all:	 ${NAME}

$(NAME): ${OBJS} 
		ar rcs  ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}


fclean:	clean
		${RM} ${NAME}

re:		fclean all