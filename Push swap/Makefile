NAME = push_swap
CC = cc
DIR_OP = operations
DIR_PRINT = ft_printf
DIR_SORT = sort
DIR_UTILS = utils
FLAGS = -Wall -Werror -Wextra -I. -I${DIR_PRINT}
SOURCES = \
	  $(DIR_OP)/push.c \
	  $(DIR_OP)/rotate_r.c \
	  $(DIR_OP)/rotate_rr.c \
	  $(DIR_OP)/swap.c \
	  $(DIR_PRINT)/ft_isdigit.c \
	  $(DIR_PRINT)/ft_itoa_long.c \
	  $(DIR_PRINT)/ft_printf.c \
	  $(DIR_PRINT)/ft_putchar.c \
	  $(DIR_PRINT)/ft_puthex.c \
	  $(DIR_PRINT)/ft_putnums.c \
	  $(DIR_PRINT)/ft_putstr.c \
	  $(DIR_SORT)/small_sort.c \
	  $(DIR_SORT)/big_sort.c \
	  $(DIR_SORT)/sort_maker.c \
	  $(DIR_UTILS)/ft_atoi_base.c \
	  $(DIR_UTILS)/ft_strlcpy.c \
	  $(DIR_UTILS)/ft_toupper.c \
	  $(DIR_UTILS)/ft_split.c \
	  $(DIR_UTILS)/ft_strtrim.c \
	  $(DIR_UTILS)/ft_strlen.c \
	  push_swap.c stack.c aux_func.c

OBJECTS = $(SOURCES:.c=.o)

all: ${NAME}

${NAME}: ${OBJECTS}
	@${CC} ${FLAGS} ${OBJECTS} -o ${NAME}

%.o: %.c
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@rm -f ${OBJECTS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
