NAME = fillit

HEADER_PATH = ./libft/
HEADER_NAME = libft.a
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

SRC_PATH = ./
SRC_NAME = main.c \
		   error.c \
		   parse.c \
		   checkbuf.c
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ = $(SRC:.c=.o)

FLAG = -Werror -Wextra -Wall

all : $(NAME)

$(NAME) :
	make -C libft
	gcc $(FLAG) $(SRC) $(HEADER) -o $(NAME)

clean :
	make clean -C libft
	rm -f $(OBJ)

fclean :
	make fclean -C libft
	rm -f $(OBJ) $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
