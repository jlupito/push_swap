/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:39:37 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/22 16:53:24 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *nptr)
{
	long	i;
	long	res;
	int		neg;

	i = 0;
	neg = 1;
	if (nptr[i] == 43 || nptr[i] == 45)
	{	
		if (nptr[i] == 45)
			neg = -neg;
		i++;
	}
	res = 0;
	while (nptr[i] && (nptr[i] > 47 && nptr[i] < 58))
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	res *= neg;
	return (res);
}

int	free_parsing(int *tab)
{
	free (tab);
	return (1);
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (parsing(argc, argv) == 1)
		exit(write(2, "Error\n", 6));
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	if (stack_a == NULL)
		exit (0);
	set_index(stack_a, argc);
	if (is_right_order(stack_a) == 1)
	{
		if (argc <= 6)
			mini_sort(&stack_a, &stack_b, argc);
		else
			main_algo(&stack_a, &stack_b, argc);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
