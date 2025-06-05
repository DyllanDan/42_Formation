NAME = minishell
CC = cc
DIR_PRINT = ft_printf
LDFLAGS = -lreadline
DIR_UTILS = utils
FLAGS = -Wall -Werror -Wextra -I. -I${DIR_PRINT}
SOURCES = \
	  $(DIR_PRINT)/ft_isdigit.c \
	  $(DIR_PRINT)/ft_itoa_long.c \
	  $(DIR_PRINT)/ft_printf.c \
	  $(DIR_PRINT)/ft_putchar.c \
	  $(DIR_PRINT)/ft_puthex.c \
	  $(DIR_PRINT)/ft_putnums.c \
	  $(DIR_PRINT)/ft_putstr.c \
	  $(DIR_UTILS)/ft_atoi_base.c \
	  $(DIR_UTILS)/ft_strlcpy.c \
	  $(DIR_UTILS)/ft_toupper.c \
	  $(DIR_UTILS)/ft_split.c \
	  $(DIR_UTILS)/ft_strtrim.c \
	  $(DIR_UTILS)/ft_strlen.c \
	  minishell.c

OBJECTS = $(SOURCES:.c=.o)

all: ${NAME}

${NAME}: ${OBJECTS}
	@${CC} ${FLAGS} ${OBJECTS} $(LDFLAGS) -o ${NAME}

%.o: %.c
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@rm -f ${OBJECTS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
