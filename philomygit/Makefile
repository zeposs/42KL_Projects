SRCS = \
end_check.c init.c philo.c routine.c utils.c

OBJ = $(SRCS:.c=.o)

NAME = philo

BONUS_NAME =

CC = cc

CFLAGS = -pthread

#COLORS!
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all : $(NAME)

$(NAME): $(OBJ)
	@echo "${GREEN}compiling philo...${NC}"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "${GREEN}compile philo success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	@echo "${GREEN}cleaning...${NC}"
	@rm -f ${OBJ}
	@rm -f ${BONUS_OBJ}
	@echo "${GREEN}clean success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all

test: re
	cd LazyPhilosophersTester && ./test.sh ../philo

.PHONY: all clean fclean re leak bonus