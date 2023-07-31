# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 20:42:17 by juhaamid          #+#    #+#              #
#    Updated: 2023/07/26 23:20:14 by juhaamid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fractol

SRCS	=	main.c \
			utils.c \
			ft_strcmp.c \
			ft_strdup.c \
			hooks.c \
			mandelbrot.c \
			fractol_init.c \
			julia.c


OBJS	=	${SRCS:.c=.o}

HEADER	=	include

PR	=	./ft_printf/libftprintf.a

# MLX		=	./mlx_linux/libmlx.a

CC		=	gcc

# MLX_DIR		=	mlx_linux

OS:= ${shell uname}
ifeq (${OS},Darwin)
	MLXDIR = ./mlx
	MLXFLG = -framework OpenGL -framework Appkit
	CFLAGS += -D OSX -Wall -Wextra -Werror -I ${HEADER} -I/usr/include -I ${MLXDIR} -O3 -Ofast -fsanitize=address -g3
else
	MLXDIR = ./mlx_linux
	MLXFLG = -lXext -lX11
	MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -lXext -lX11 -L/usr/lib -Imlx_linux 
	CFLAGS += -D LINUX -Wall -Wextra -Werror -I ${HEADER} -I/usr/include -I ${MLXDIR} -O3 -Ofast -fsanitize=address -g3
	MLX = ./mlx_linux/libmlx.a
endif
PR_DIR	= ft_printf

# CFLAGS	=	 -Wall -Wextra -Werror -I ${HEADER} -I/usr/include -I ${MLXDIR} -O3 -Ofast -fsanitize=address -g3

# MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -lXext -lX11 -L/usr/lib -Imlx_linux 

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 


${NAME}:	$(PR) $(MLXDIR) ${OBJS} 
			${CC} ${CFLAGS} ${MLX_FLAGS} ${OBJS} ${MLX} ${PR} -o ${NAME} -lm -lXext -lX11 

$(PR):	
			${MAKE} -C ./ft_printf
# 			${MAKE} -C libft bonus

${MLXDIR}:		
			${MAKE} -C $(MLXDIR)

all:		${NAME} ${PR} ${MLX}

clean:		
			rm -f ${OBJS}
			${MAKE} -C $(MLXDIR)

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
