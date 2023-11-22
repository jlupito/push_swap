/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:47:02 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/22 16:53:02 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	last = (ft_lstlast(*stack));
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
}

void	process_ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	process_rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	process_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
