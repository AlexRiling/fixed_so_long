/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:44:56 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 22:24:15 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

static int	parse_and_validate_map(t_game_state *game_state,
		t_counts *counts, char *file_path)
{
	game_state->map = parse_map(
			file_path,
			&game_state->rows,
			&game_state->cols);
	if (!game_state->map)
	{
		ft_printf("Failed to parse map.\n");
		return (0);
	}
	if (!validate_map(
			game_state->map,
			game_state->rows,
			game_state->cols,
			counts))
	{
		free_map(game_state->map);
		ft_printf("Invalid map.\n");
		return (0);
	}
	return (1);
}

static int	initialize_player(t_game_state *game_state)
{
	game_state->player = malloc(sizeof(t_player));
	if (!game_state->player)
	{
		ft_printf("Memory allocation error.\n");
		return (0);
	}
	game_state->player->move_count = 0;
	find_player(
		game_state->map,
		game_state->player,
		game_state->rows,
		game_state->cols);
	return (1);
}

void	initialize_game_state(t_game_state *game_state, t_data *data,
		t_counts *counts, char **argv)
{
	if (!parse_and_validate_map(game_state, counts, argv[1]))
		exit(1);
	if (!initialize_player(game_state))
		exit(1);
	game_state->collectibles = counts->collectibles;
	game_state->graphics = data;
}

int	main(int argc, char **argv)
{
	t_game_state	game_state;
	t_data			data;
	t_counts		counts;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	counts.player = 0;
	counts.collectibles = 0;
	counts.exits = 0;
	initialize_game_state(
		&game_state,
		&data,
		&counts,
		argv);
	init_window(&data, &game_state);
	return (0);
}
