
NAME = pipex

SRC = src/

FILES = main.c path.c util.c ft_split.c

CC = cc

OBJ = $(addprefix $(SRC), $(FILES:.c=.o))

FLAGS = -Wall -Werror -Wextra

all:	${NAME}

${NAME}: ${OBJ}
		${CC} ${FLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
