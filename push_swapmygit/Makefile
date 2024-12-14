SRCS = \
checks.c \
error_printing.c \
lstutils.c \
lstutils2.c \
minichecks.c \
operations.c \
operations2.c \
pushswap.c \
rotatenpush.c \
rotatetype.c \
solverutils_ab.c \
sort.c \
stackhandling.c \

OBJ = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

LIB = libft.a

LIBDIR = libft

#COLORS!
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all : $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo "${GREEN}compiling push_swap...${NC}"
	@$(CC) $(OBJ) -lft -L. -o $(NAME) libft.a
	@echo "${GREEN}compile push_swap success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIB) :
	@echo "${GREEN}compiling libft...${NC}"
	@$(MAKE) -C $(LIBDIR)
	@mv $(LIBDIR)/$(LIB) .
	@echo "${GREEN}compile libft success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

clean :
	@echo "${GREEN}cleaning...${NC}"
	@rm -f ${OBJ}
	@rm -f $(LIB)
	@$(MAKE) -C $(LIBDIR) clean
	@echo "${GREEN}clean success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

fclean : clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re leak