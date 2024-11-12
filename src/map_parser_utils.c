/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:44:02 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 22:24:15 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	count_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}

int	check_row_lengths(char **map, int rows, int *cols)
{
	int	i;

	*cols = ft_strlen(map[0]);
	i = 1;
	while (i < rows)
	{
		if ((int)ft_strlen(map[i]) != *cols)
		{
			ft_printf("Error: Inconsistent row lengths in map.\n");
			return (0);
		}
		i++;
	}
	return (1);
}
