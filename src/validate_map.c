/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:59:35 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 22:33:29 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	validate_map(char **map, int rows, int cols, t_counts *counts)
{
	if (!validate_map_elements(map, rows, cols))
	{
		ft_printf("Error: Invalid characters in map.\n");
		return (0);
	}
	count_elements(map, rows, cols, counts);
	if (!is_map_surrounded_by_walls(map, rows, cols))
	{
		ft_printf("Error: Map is not surrounded by walls.\n");
		return (0);
	}
	if (counts->player != 1 || counts->exits < 1 || counts->collectibles < 1)
	{
		ft_printf("Error: Invalid number of players, exits, or "
			"collectibles.\n");
		return (0);
	}
	return (1);
}
