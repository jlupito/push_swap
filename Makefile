NAME= push_swap

BONUS= checker

CFLAGS= -Wall -Wextra -Werror

CC = gcc

SRC= instr_push.c instr_revrotate.c instr_rotate.c instr_swap.c parsing.c push_swap_lst_utils.c \
		push_swap_cost.c push_swap_locate.c push_swap_setup.c push_swap.c sort_algo.c sort_mini.c

OBJ= $(SRC:.c=.o)

BONUS_SRC= instr_push.c instr_revrotate.c instr_rotate.c instr_swap.c parsing.c push_swap_lst_utils.c \
			push_swap_cost.c push_swap_locate.c push_swap_setup.c sort_algo.c sort_mini.c \
				checker.c checker_utils.c get_next_line.c get_next_line_utils.c

BONUS_OBJ= $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS)
	
.PHONY: all clean fclean re bonus