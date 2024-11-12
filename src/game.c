/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:37:43 by ariling           #+#    #+#             */
/*   Updated: 2024/11/12 11:08:21 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

/* Finds the player's starting position in the map */
void	find_player(char **map, t_player *player, int rows, int cols)
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
			{
				player->x = j;
				player->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

/* Checks if the player can move to the specified position */
int	can_move(char **map, int new_x, int new_y)
{
	if (map[new_y][new_x] == '1')
		return (0);
	return (1);
}

static void	handle_exit(t_game_state *game_state)
{
	if (game_state->collectibles == 0)
	{
		ft_printf("You reached the exit! Game over.\n");
		free_game_state(game_state);
		exit(0);
	}
	else
	{
		ft_printf("You need to collect all items before exiting!\n");
	}
}

/* Handles collecting items */
static void	collect_item(t_game_state *game_state, int new_x, int new_y)
{
	game_state->map[new_y][new_x] = '0';
	game_state->collectibles--;
	ft_printf("Collected a collectible! Remaining: %d\n",
		game_state->collectibles);
}

/* Handles player movement and interactions */
void	move_player(t_game_state *game_state, int new_x, int new_y)
{
	t_player	*player;
	t_data		*data;
	char		**map;

	player = game_state->player;
	data = game_state->graphics;
	map = game_state->map;
	if (can_move(map, new_x, new_y))
	{
		if (map[new_y][new_x] == 'E')
		{
			handle_exit(game_state);
			if (game_state->collectibles > 0)
				return ;
		}
		if (map[new_y][new_x] == 'C')
			collect_item(game_state, new_x, new_y);
		map[player->y][player->x] = '0';
		player->x = new_x;
		player->y = new_y;
		map[player->y][player->x] = 'P';
		player->move_count++;
		ft_printf("Move count: %d\n", player->move_count);
	}
}
