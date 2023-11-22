/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:12:29 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/22 16:53:18 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_lstnew(int val)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->val = val;
	new->index = 0;
	new->position = 0;
	new->next = (NULL);
	return (new);
}

t_stack	*ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*add_last;

	if (!new)
	{
		free_stack(lst);
		return (NULL);
	}
	if (!*lst)
	{
		*lst = new;
		return (NULL);
	}
	else
	{
		add_last = ft_lstlast(*lst);
		add_last->next = new;
	}
	return (*lst);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstbeforelast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	unsigned int	nbelements;

	nbelements = 0;
	while (lst)
	{
		lst = lst->next;
		nbelements++;
	}
	return (nbelements);
}
