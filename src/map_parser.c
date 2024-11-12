/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:45:08 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 22:24:15 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char	*read_and_append(int fd, char *buffer)
{
	char	tmp[1024];
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, tmp, 1023);
		if (bytes_read <= 0)
			break ;
		tmp[bytes_read] = '\0';
		buffer = ft_strjoin_free(buffer, tmp);
		if (!buffer)
		{
			perror("Error allocating memory for buffer");
			return (NULL);
		}
	}
	if (bytes_read < 0)
	{
		perror("Error reading map file");
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*read_file_into_buffer(const char *file_path)
{
	int		fd;
	char	*buffer;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		return (NULL);
	}
	buffer = NULL;
	buffer = read_and_append(fd, buffer);
	close(fd);
	return (buffer);
}

char	**parse_map(const char *file_path, int *rows, int *cols)
{
	char	*buffer;
	char	**map;

	buffer = read_file_into_buffer(file_path);
	if (!buffer)
		return (NULL);
	map = ft_split(buffer, '\n');
	free(buffer);
	if (!map)
	{
		ft_printf("Error splitting map into lines.\n");
		return (NULL);
	}
	*rows = count_rows(map);
	if (!check_row_lengths(map, *rows, cols))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
