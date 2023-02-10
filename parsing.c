/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:31:21 by jarthaud          #+#    #+#             */
/*   Updated: 2023/02/03 16:28:12 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(char *argv)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (argv[j] == 45 || argv[j] == 43)
		{
			if (argv[j + 1] < 48 || argv[j + 1] > 57)
				return (1);
			j++;
		}
		else if (argv[j] >= 48 && argv[j] <= 57)
		{
			if (argv[j + 1] && (argv[j + 1] < 48 || argv[j + 1] > 57))
				return (1);
			j++;
		}
		else
			return (1);
	}
	return (0);
}

int	check_dup(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (tab[i] == tab[j])
				return (free_parsing(tab));
			else
				j++;
		}
		i++;
	}
	free (tab);
	return (0);
}

int	check_zeros(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argv[i] == 43 || argv[i] == 45)
		i++;
	while (argv[i] == '0' && argv[i])
		i++;
	while (argv[i])
	{
		i++;
		j++;
	}
	if (j > 10)
		return (1);
	else
		return (0);
}

int	check_int(int argc, char **argv)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (check_zeros(argv[i]) == 0)
		{
			if (ft_atol(argv[i]) >= INT_MIN && ft_atol(argv[i]) <= INT_MAX)
			{
				tab[i - 1] = ft_atol(argv[i]);
				i++;
			}
			else
				return (free_parsing(tab));
		}
		else
			return (free_parsing(tab));
	}
	if (check_dup(tab, argc) == 0)
		return (0);
	return (1);
}

int	parsing(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		exit (0);
	else
	{
		while (argv[i])
		{
			if (check_numbers(argv[i]) == 1)
				return (1);
			i++;
		}
		if (check_int(argc, argv) == 1)
			return (1);
		return (0);
	}
}
