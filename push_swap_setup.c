/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:45:51 by jarthaud          #+#    #+#             */
/*   Updated: 2023/02/03 11:04:11 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		(*stack)->val = 0;
		(*stack)->index = 0;
		(*stack)->position = 0;
		tmp = *stack;
		*stack = tmp->next;
		free(tmp);
	}
	*stack = (NULL);
}

int	is_right_order(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->val < stack->next->val)
			stack = stack->next;
		else
			return (1);
	}
	return (0);
}

void	set_position(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->position = i;
		stack = stack->next;
		i++;
	}
}

void	set_index_2(t_stack *tmp, int min, int i)
{
	while (tmp)
	{
		if (tmp->val == min)
		{
			tmp->index = i;
			break ;
		}
		tmp = tmp->next;
	}
}

void	set_index(t_stack *stack, int argc)
{
	int		i;
	int		min;
	t_stack	*tmp;

	i = 1;
	while (i < argc)
	{
		tmp = stack;
		while (tmp->index != 0)
			tmp = tmp->next;
		min = tmp->val;
		while (tmp)
		{
			if (tmp->index == 0 && min > tmp->val)
				min = tmp->val;
			tmp = tmp->next;
		}
		tmp = stack;
		set_index_2(tmp, min, i);
		i++;
	}
}
