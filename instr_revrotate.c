/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_revrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:19:31 by jarthaud          #+#    #+#             */
/*   Updated: 2023/02/02 15:55:25 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*beforelast;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (ft_lstlast(*stack));
	beforelast = (ft_lstbeforelast(*stack));
	beforelast->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	process_rra(t_stack **stack_a)
{
	revrotate(stack_a);
	write(1, "rra\n", 4);
}

void	process_rrb(t_stack **stack_b)
{
	revrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	process_rrr(t_stack **stack_a, t_stack **stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
	write(1, "rrr\n", 4);
}
