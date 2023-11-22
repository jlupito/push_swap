/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:26:32 by jarthaud          #+#    #+#             */
/*   Updated: 2023/02/06 11:12:42 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int				val;
	int				index;
	int				position;
	struct s_stack	*next;
}	t_stack;

// check error functions
long	ft_atol(const char *nptr);
int		check_numbers(char *argv);
int		check_int(int argc, char **argv);
int		check_dup(int *tab, int size);
int		check_zeros(char *argv);
int		parsing(int argc, char **argv);
int		free_parsing(int *tab);

// list functions
t_stack	*ft_lstnew(int val);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstbeforelast(t_stack *lst);
t_stack	*ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*fill_stack(int argc, char **argv);
int		ft_lstsize(t_stack *lst);
void	free_stack(t_stack **stack);

// swap instructions
void	swap(t_stack **stack);
void	process_sa(t_stack **stack_a);
void	process_sb(t_stack **stack_b);
void	process_ss(t_stack **stack_a, t_stack **stack_b);

// push instructions
void	push(t_stack **stack1, t_stack **stack2);
void	process_pa(t_stack **stack_b, t_stack **stack_a);
void	process_pb(t_stack **stack_a, t_stack **stack_b);

// rotate instructions
void	rotate(t_stack **stack);
void	process_ra(t_stack **stack_a);
void	process_rb(t_stack **stack_b);
void	process_rr(t_stack **stack_a, t_stack **stack_b);

// reverse rotate instructions
void	revrotate(t_stack **stack);
void	process_rra(t_stack **stack_a);
void	process_rrb(t_stack **stack_b);
void	process_rrr(t_stack **stack_a, t_stack **stack_b);

// push swap functions
int		is_right_order(t_stack *stack);
void	mini_sort_two(t_stack **stack_a);
void	mini_sort_three(t_stack **stack_a);
void	mini_sort_five(t_stack **stack_a, t_stack **stack_b, int i);
void	mini_sort(t_stack **stack_a, t_stack **stack_b, int argc);
void	main_algo(t_stack **stack_a, t_stack **stack_b, int argc);
t_stack	*find_highest(t_stack *stack);
t_stack	*find_lowest(t_stack *stack);
t_stack	*find_next_lowest(t_stack *stack_a, t_stack *stack_b);
t_stack	*find_next_highest(t_stack *stack_a, t_stack *stack_b);
void	set_index(t_stack *stack, int argc);
void	set_index_2(t_stack *tmp, int min, int i);
void	set_position(t_stack *stack);
int		cost_to_top(t_stack *stack, t_stack *element);
int		total_cost(t_stack *tmp, t_stack *stack_a, t_stack *stack_b);
t_stack	*cheapest_move(t_stack *stack_a, t_stack *stack_b);
void	process_cheapest(t_stack **stack_a, t_stack **stack_b);
void	push_back(t_stack **stack_a, t_stack **stack_b);
void	tidy_stack_lowest(t_stack **stack);
void	push_to_top_a(t_stack *to_move_a, t_stack **stack_a);
void	push_to_top_b(t_stack *next_lowest_b, t_stack **stack_b);
int		highest_cost(int a, int b);

//checker
char	*get_next_line(int fd, int flag);
char	*get_new_start(char *stash, int read_nb);
char	*get_line(char *stash);
void	error_free(char *stash);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	exit_error(t_stack **stack_a, t_stack **stack_b, char *str);
char	*instr_checker(t_stack **stack_a, t_stack **stack_b, char *str);
char	*instr_checker_r(t_stack **stack_a, t_stack **stack_b, char *str);
void	get_instructions(char *str, t_stack **a, t_stack **b);

#endif