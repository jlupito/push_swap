/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:21:18 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/22 16:53:12 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*cheapest;
	t_stack	*tmp_a;

	set_position(stack_a);
	set_position(stack_b);
	cheapest = stack_a;
	tmp_a = stack_a;
	while (tmp_a)
	{
		if (total_cost(stack_a, tmp_a, stack_b) == 0)
		{
			cheapest = tmp_a;
			return (cheapest);
		}
		else if (total_cost(stack_a, tmp_a, stack_b)
			< total_cost(stack_a, cheapest, stack_b))
			cheapest = tmp_a;
		tmp_a = tmp_a->next;
	}
	return (cheapest);
}

int	total_cost(t_stack *stack_a, t_stack *tmp_a, t_stack *stack_b)
{
	t_stack	*next_lowest;
	int		cost;

	next_lowest = find_next_lowest(tmp_a, stack_b);
	cost = 0;
	if (tmp_a != stack_a && next_lowest != stack_b)
	{
		if ((tmp_a->position <= ((ft_lstsize(stack_a) / 2)
					+ (ft_lstsize(stack_a) % 2))) && (next_lowest->position
				<= ((ft_lstsize(stack_b) / 2) + (ft_lstsize(stack_b) % 2))))
			cost = highest_cost((cost_to_top(stack_a, tmp_a)),
					(cost_to_top(stack_b, next_lowest)));
		if ((tmp_a->position > ((ft_lstsize(stack_a) / 2)
					+ (ft_lstsize(stack_a) % 2))) && (next_lowest->position
				> ((ft_lstsize(stack_b) / 2) + (ft_lstsize(stack_b) % 2))))
			cost = highest_cost((cost_to_top(stack_a, tmp_a)),
					(cost_to_top(stack_b, next_lowest)));
		else
			cost = cost_to_top(stack_a, tmp_a)
				+ cost_to_top(stack_b, next_lowest);
	}
	else if (tmp_a == stack_a || next_lowest == stack_b)
		cost = cost_to_top(stack_a, tmp_a) + cost_to_top(stack_b, next_lowest);
	return (cost);
}

int	highest_cost(int a, int b)
{
	int	i;

	i = 0;
	if (a >= b)
		i = a;
	if (b > a)
		i = b;
	return (i);
}

int	cost_to_top(t_stack *stack, t_stack *element)
{
	int	cost;

	cost = 0;
	if (element->position <= ((ft_lstsize(stack) / 2)
			+ (ft_lstsize(stack) % 2)))
		cost = element->position - 1;
	else
		cost = (ft_lstsize(stack) - element->position) + 1;
	return (cost);
}
