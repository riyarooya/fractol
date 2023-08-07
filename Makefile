# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 20:42:17 by juhaamid          #+#    #+#              #
#    Updated: 2023/08/07 09:53:21 by juhaamid         ###   ########.fr        #
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

CC		=	cc

OS:= ${shell uname}
ifeq (${OS},Darwin)
	MLXDIR = ./mlx
	MLXFLG = -framework OpenGL -framework Appkit
	CFLAGS += -D OSX -Wall -Wextra -Werror -I ${HEADER} -I/usr/include -I ${MLXDIR} -O3 -Ofast 
	MLX = ./mlx/libmlx.a
else
	MLXDIR = ./mlx_linux
	MLXFLG = -lXext -lX11
	MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -lXext -lX11 -L/usr/lib -Imlx_linux 
	CFLAGS += -D LINUX -Wall -Wextra -Werror -I ${HEADER} -I/usr/include -I ${MLXDIR} -O3 -Ofast 
	MLX = ./mlx_linux/libmlx.a
endif

PR_DIR	= ft_printf

all:	${PR} ${MLX} ${NAME} 


.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 


${NAME}:	$(PR) ${OBJS} $(MLX)
			${CC} ${CFLAGS} ${MLXFLG} ${OBJS} ${MLX} ${PR} -o ${NAME}

$(MLX):	
			echo fvsljndf
			${MAKE} -C ./mlx  

$(PR):	
			${MAKE} -C ./ft_printf  

${MLXDIR}:		
			${MAKE} -C $(MLXDIR)


clean:		
			rm -f ${OBJS}
			${MAKE} clean -C  $(MLXDIR) 
			${MAKE} fclean -C  ./ft_printf

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
