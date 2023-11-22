NAME= push_swap
BONUS= checker
CFLAGS= -Wall -Wextra -Werror
CC = gcc

SRC= sources/instr_push.c sources/instr_revrotate.c sources/instr_rotate.c \
		sources/instr_swap.c sources/parsing.c sources/push_swap_lst_utils.c \
		sources/push_swap_cost.c sources/push_swap_locate.c sources/push_swap_setup.c \
		sources/push_swap.c sources/sort_algo.c sources/sort_mini.c \

OBJ= $(SRC:.c=.o)

BONUS_SRC= sources/instr_push.c sources/instr_revrotate.c sources/instr_rotate.c sources/instr_swap.c \
		sources/parsing.c sources/push_swap_lst_utils.c sources/push_swap_cost.c sources/push_swap_locate.c \
		sources/push_swap_setup.c sources/sort_algo.c sort_mini.c sources/checker.c sources/checker_utils.c \
		sources/get_next_line.c sources/get_next_line_utils.c \

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