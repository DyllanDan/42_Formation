NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h

SRCS = ft_itoa_long.c ft_putnums.c ft_toupper.c ft_printf.c \
		ft_putchar.c ft_putstr.c ft_puthex.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
