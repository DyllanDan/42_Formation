#Name
NAME = Fdf

#Compiler
CC = gcc

#Flags
CFLAGS = -Wall -Wextra -Werror -Imlx

#LINKS
LINKS = -I /usr/local/include -L /usr/local/lib \
	-l mlx -l ft -framework OpenGL -framework Appkit

SRC = prototype.c

OBJ = $(subst .c,.o,$(SRC))

%.o: %.c
	$(CC) $(CFLAFS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(FLAGS) $(LINKS)
