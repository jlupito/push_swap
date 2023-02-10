/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:12:28 by jarthaud          #+#    #+#             */
/*   Updated: 2023/02/03 12:28:32 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_new_start(char *stash, int read_nb)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	while (stash[j] != '\n' && stash[j])
		j++;
	if (read_nb == 0)
		return (free(stash), NULL);
	str = malloc(sizeof(char) * (ft_strlen(stash) - j + 1));
	if (!str)
		return (NULL);
	j++;
	i = 0;
	while (stash[j])
		str[i++] = stash[j++];
	str[i] = '\0';
	free(stash);
	return (str);
}

char	*get_line(char *stash)
{
	int		i;
	char	*res;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		res[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

void	error_free(char *stash)
{
	free(stash);
	exit(0);
}

char	*get_next_line(int fd, int flag)
{
	static char	*stash;
	char		*buffer;
	int			read_nb;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (flag == 1)
		error_free(stash);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_nb = 1;
	while (!(ft_strchr(stash, '\n')) && read_nb != 0)
	{
		read_nb = read(fd, buffer, BUFFER_SIZE);
		if (read_nb <= 0 && !stash)
			return (free(buffer), NULL);
		buffer[read_nb] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	buffer = get_line(stash);
	stash = get_new_start(stash, read_nb);
	return (buffer);
}
