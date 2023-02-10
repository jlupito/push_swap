/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:34:01 by jarthaud          #+#    #+#             */
/*   Updated: 2023/02/01 11:58:45 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_two(t_stack **stack_a)
{
	if ((*stack_a)->val > (*stack_a)->next->val)
		process_sa(stack_a);
}

void	mini_sort_three(t_stack **stack_a)
{
	while (is_right_order(*stack_a) == 1)
	{
		if ((*stack_a) == find_highest(*stack_a))
			process_ra(stack_a);
		else if (ft_lstlast(*stack_a) == find_highest(*stack_a))
			process_sa(stack_a);
		else if ((*stack_a)->next == find_highest(*stack_a))
			process_rra(stack_a);
	}
}

void	mini_sort_five(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*lowest;

	while (ft_lstsize(*stack_a) != 3)
	{
		lowest = find_lowest(*stack_a);
		if (*stack_a == lowest)
			process_pb(stack_a, stack_b);
		else
		{
			set_position(*stack_a);
			while (*stack_a != lowest)
			{
				if (lowest->position >= (ft_lstsize(*stack_a) / 2)
					+ (ft_lstsize(*stack_a) % 2))
					process_rra(stack_a);
				else
					process_ra(stack_a);
			}
			process_pb(stack_a, stack_b);
		}
	}
	mini_sort_three(stack_a);
	process_pa(stack_b, stack_a);
	while (i-- > 1)
		process_pa(stack_b, stack_a);
}

void	mini_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 3)
		mini_sort_two(stack_a);
	else if (argc == 4)
		mini_sort_three(stack_a);
	else if (argc == 5)
		mini_sort_five(stack_a, stack_b, 1);
	else if (argc == 6)
		mini_sort_five(stack_a, stack_b, 2);
}
