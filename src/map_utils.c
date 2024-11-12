/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:44:45 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 22:04:01 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	count_elements(char **map, int rows, int cols, t_counts *counts)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'P')
				counts->player++;
			else if (map[i][j] == 'C')
				counts->collectibles++;
			else if (map[i][j] == 'E')
				counts->exits++;
			j++;
		}
		i++;
	}
}

int	is_map_surrounded_by_walls(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < rows - 1)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_map_elements(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
