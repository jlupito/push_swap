/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:46:53 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/22 16:52:47 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(t_stack **a, t_stack **b, char *str)
{
	free_stack(a);
	free_stack(b);
	free(str);
	write(2, "Error\n", 6);
	get_next_line(0, 1);
	exit(0);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack;
	int			i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (i == 1)
			stack = ft_lstnew(ft_atol(argv[i]));
		else
			stack = ft_lstadd_back(&stack, ft_lstnew(ft_atol(argv[i])));
		i++;
	}
	return (stack);
}

void	get_instructions(char *str, t_stack **a, t_stack **b)
{
	while (str != NULL)
	{
		if (str[0] == 'r')
			str = instr_checker_r(a, b, str);
		else if (str[0] == 'p' || str[0] == 's')
			str = instr_checker(a, b, str);
		else
			exit_error(a, b, str);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	if (parsing(argc, argv) == 1)
		exit (write(2, "Error\n", 6));
	b = NULL;
	a = fill_stack(argc, argv);
	if (a == NULL)
		exit (0);
	str = get_next_line(0, 0);
	get_instructions(str, &a, &b);
	if (!is_right_order(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&b);
	free_stack(&a);
	return (0);
}
