NAME = philo
CC = cc
FLAGS = -Wall -Werror -Wextra -pthread -I.
AUX_DIR = aux_func
TIME_DIR = time_func
SOURCES = $(AUX_DIR)/ft_atoi_base.c \
		$(AUX_DIR)/ft_strlcpy.c \
		$(AUX_DIR)/ft_isdigit.c \
		$(TIME_DIR)/times.c \
		main.c activities.c philos.c create_item.c \
		monitor.c errors.c


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
