/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:46:49 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/22 16:52:43 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*instr_checker(t_stack **a, t_stack **b, char *str)
{
	if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		push(b, a);
	else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		push(a, b);
	else if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		swap(a);
	else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		swap(b);
	else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
	{
		swap(a);
		swap(b);
	}
	else
		exit_error(a, b, str);
	free(str);
	return (get_next_line(0, 0));
}

char	*instr_checker_r(t_stack **a, t_stack **b, char *str)
{
	if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		rotate(a);
	else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		rotate(b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
	{
		rotate(a);
		rotate(b);
	}
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		revrotate(a);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		revrotate(b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
	{
		revrotate(a);
		revrotate(b);
	}
	else
		exit_error(a, b, str);
	free(str);
	return (get_next_line(0, 0));
}

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
