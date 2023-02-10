/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_locate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:34:59 by jarthaud          #+#    #+#             */
/*   Updated: 2023/02/09 17:03:39 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_highest(t_stack *stack)
{
	t_stack	*highest;

	highest = stack;
	while (stack)
	{
		if (stack->index > highest->index)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

t_stack	*find_lowest(t_stack *stack)
{
	t_stack	*lowest;

	lowest = stack;
	while (stack)
	{
		if (stack->index < lowest->index)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}

t_stack	*find_next_lowest(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*next_lowest;
	t_stack	*tmp_b;

	tmp_b = stack_b;
	if (stack_a->index < find_lowest(stack_b)->index
		|| stack_a->index > find_highest(stack_b)->index)
		return (find_highest(stack_b));
	next_lowest = find_lowest(stack_b);
	while (tmp_b)
	{
		if (tmp_b->index > next_lowest->index && tmp_b->index < stack_a->index)
			next_lowest = tmp_b;
		tmp_b = tmp_b->next;
	}
	return (next_lowest);
}

t_stack	*find_next_highest(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*next_highest;
	t_stack	*tmp_a;

	tmp_a = stack_a;
	if (stack_b->index > find_highest(stack_a)->index
		|| stack_b->index < find_lowest(stack_a)->index)
		return (find_lowest(stack_a));
	next_highest = find_highest(stack_a);
	while (tmp_a)
	{
		if (tmp_a->index < next_highest->index && tmp_a->index > stack_b->index)
			next_highest = tmp_a;
		tmp_a = tmp_a->next;
	}
	return (next_highest);
}

void	tidy_stack_lowest(t_stack **stack)
{
	set_position(*stack);
	while (find_lowest(*stack) != *stack)
	{
		if (find_lowest(*stack)->position <= ((ft_lstsize(*stack) / 2)
				+ (ft_lstsize(*stack) % 2)))
			process_ra(stack);
		else
			process_rra(stack);
	}
}
