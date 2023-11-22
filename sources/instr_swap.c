/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:23:14 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/22 16:53:05 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*third;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack);
	third = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->next = third;
}

void	process_sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	process_sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	process_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
