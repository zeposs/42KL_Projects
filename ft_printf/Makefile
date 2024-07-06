NAME = libftprintf.a

SRCS = 	ft_lowerhex.c ft_ptr.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_uint.c ft_upperhex.c ft_printf.c typelist.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.so

re: fclean all

.PHONY: all so clean fclean re