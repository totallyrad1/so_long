CC = cc
SRC = get_next_line.c get_next_line_utils.c parsingmap.c parsingmap1.c renderingtools.c rerenderingtools.c so_long.c tools.c tools1.c tools3.c tools2.c
MLX_API = -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror 
NAME = so_long

$(NAME): $(OBJ) so_long.h get_next_line.h
	$(CC) $(FLAGS) $(MLX_API) $(OBJ) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all