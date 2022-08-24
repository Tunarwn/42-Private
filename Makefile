MINILIBX	= minilibx/libmlx.a
CC 			= gcc -glldb
FLAGS 		= -Wall -Wextra -Werror
NAME 		= so_long
LFLAGS		= -framework OpenGL -framework AppKit
INCLUDE		= inc
SRCS		= src/utils_1.c src/main.c src/ft_split.c src/create.c src/move.c src/control.c

all: $(NAME)

$(NAME) :  $(MINILIBX)
	$(CC) $(SRCS) $(LFLAGS) -o $(NAME) minilibx/libmlx.a ft_printf/libftprintf.a  -I $(INCLUDE)

$(MINILIBX):
	make -C minilibx
	make -C ft_printf
	@echo "\033[0;95mMINILIBX compile OLDU"

run :all
	./$(NAME) maps/map1.ber
re : fclean all
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make -C minilibx clean
	make -C ft_printf fclean

norm:
	norminette src/*.c
	norminette inc/*.h
	norminette ft_printf/*.c
