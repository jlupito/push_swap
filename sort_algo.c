/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:25:22 by jarthaud          #+#    #+#             */
/*   Updated: 2023/02/02 10:48:01 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*to_move_a;
	t_stack	*next_lowest_b;

	set_position(*stack_a);
	set_position(*stack_b);
	to_move_a = cheapest_move(*stack_a, *stack_b);
	next_lowest_b = find_next_lowest(to_move_a, *stack_b);
	while (to_move_a != *stack_a && next_lowest_b != *stack_b)
	{
		if ((to_move_a->position <= ((ft_lstsize(*stack_a) / 2)
					+ (ft_lstsize(*stack_a) % 2))) && (next_lowest_b->position
				<= ((ft_lstsize(*stack_b) / 2) + (ft_lstsize(*stack_b) % 2))))
			process_rr(stack_a, stack_b);
		if ((to_move_a->position > ((ft_lstsize(*stack_a) / 2)
					+ (ft_lstsize(*stack_a) % 2))) && (next_lowest_b->position
				> ((ft_lstsize(*stack_b) / 2) + (ft_lstsize(*stack_b) % 2))))
			process_rrr(stack_a, stack_b);
		else
			break ;
	}
	push_to_top_a(to_move_a, stack_a);
	push_to_top_b(next_lowest_b, stack_b);
	process_pb(stack_a, stack_b);
}

void	push_to_top_a(t_stack *to_move_a, t_stack **stack_a)
{
	set_position(*stack_a);
	while (to_move_a != *stack_a)
	{
		if (to_move_a->position <= ((ft_lstsize(*stack_a) / 2)
				+ (ft_lstsize(*stack_a) % 2)))
			process_ra(stack_a);
		else
			process_rra(stack_a);
	}
}

void	push_to_top_b(t_stack *next_lowest_b, t_stack **stack_b)
{
	set_position(*stack_b);
	while (next_lowest_b != *stack_b)
	{
		if (next_lowest_b->position <= ((ft_lstsize(*stack_b) / 2)
				+ (ft_lstsize(*stack_b) % 2)))
			process_rb(stack_b);
		else
			process_rrb(stack_b);
	}
}

void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*next_highest_a;

	set_position(*stack_a);
	next_highest_a = find_next_highest(*stack_a, *stack_b);
	while (next_highest_a != *stack_a)
	{
		if (next_highest_a->position <= ((ft_lstsize(*stack_a) / 2)
				+ (ft_lstsize(*stack_a) % 2)))
			process_ra(stack_a);
		else
			process_rra(stack_a);
	}
	process_pa(stack_b, stack_a);
}

void	main_algo(t_stack **stack_a, t_stack **stack_b, int argc)
{
	process_pb(stack_a, stack_b);
	process_pb(stack_a, stack_b);
	if (argc >= 200)
	{
		while (ft_lstsize(*stack_a) > 60 && is_right_order(*stack_a) == 1)
			process_cheapest(stack_a, stack_b);
		if (ft_lstsize(*stack_a) == 60 && is_right_order(*stack_a) == 1)
			mini_sort_five(stack_a, stack_b, 57);
	}
	else
	{
		while (ft_lstsize(*stack_a) > 3 && is_right_order(*stack_a) == 1)
			process_cheapest(stack_a, stack_b);
		if (ft_lstsize(*stack_a) == 3 && is_right_order(*stack_a) == 1)
			mini_sort_three(stack_a);
	}
	while (ft_lstsize(*stack_b) > 0)
		push_back(stack_a, stack_b);
	if (*stack_a != find_lowest(*stack_a))
		tidy_stack_lowest(stack_a);
}
