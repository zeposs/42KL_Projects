SRC			= main.cpp Harl.cpp

CC			= c++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME		= program

all:	${NAME}

${NAME}: ${SRC}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all