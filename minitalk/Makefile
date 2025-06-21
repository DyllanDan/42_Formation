NAME = client
NAME2 = server
CC = cc
DIR_PRINT = ft_printf
FLAGS = -Wall -Werror -Wextra -I. -I${DIR_PRINT}
SOURCES = ${DIR_PRINT}/ft_isdigit.c \
	  ${DIR_PRINT}/ft_itoa_long.c \
	  ${DIR_PRINT}/ft_printf.c \
	  ${DIR_PRINT}/ft_putchar.c \
	  ${DIR_PRINT}/ft_puthex.c \
	  ${DIR_PRINT}/ft_putnums.c \
	  ${DIR_PRINT}/ft_putstr.c \
	  ${DIR_PRINT}/ft_strlcpy.c \
	  ${DIR_PRINT}/ft_toupper.c \
	  client.c ft_atoi_base.c

SOURCES2 = ${DIR_PRINT}/ft_isdigit.c \
	   ${DIR_PRINT}/ft_itoa_long.c \
	   ${DIR_PRINT}/ft_printf.c \
	   ${DIR_PRINT}/ft_putchar.c \
	   ${DIR_PRINT}/ft_puthex.c \
	   ${DIR_PRINT}/ft_putnums.c \
	   ${DIR_PRINT}/ft_putstr.c \
	   ${DIR_PRINT}/ft_strlcpy.c \
	   ${DIR_PRINT}/ft_toupper.c \
	   server.c ft_strdup.c ft_strjoin.c


OBJECTS = $(SOURCES:.c=.o)
OBJECTS2 = $(SOURCES2:.c=.o)

all: ${NAME} ${NAME2}

${NAME}: ${OBJECTS}
	@${CC} ${FLAGS} ${OBJECTS} -o ${NAME}

${NAME2}: ${OBJECTS2}
	@${CC} ${FLAGS} ${OBJECTS2} -o ${NAME2}


%.o: %.c
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@rm -f ${OBJECTS} ${OBJECTS2}

fclean:
	@rm -f ${NAME} ${NAME2}

re: fclean all

.PHONY: all clean fclean re
