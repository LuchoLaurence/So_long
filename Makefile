SRCS = so_long.c verif_args.c verif_map.c verif_elem.c find.c show_map.c ft_move.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = ${SRCS:<.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
LIB =libft/libft.a

all : ${NAME}

$(LIB) :
	make -C ./libft

${NAME} : ${OBJS} $(LIB)
	${CC} ${CFLAGS} ${LDFLAGS} -I so_long.h -o ${NAME} ${OBJS} -L ./libft -lft

clean :
	make clean -C ./libft

fclean :
	rm -f ${NAME}
	make fclean -C ./libft

re : fclean all

.PHONY : all flcean clean re .c