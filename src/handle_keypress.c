/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:21:35 by ariling           #+#    #+#             */
/*   Updated: 2024/11/12 11:06:29 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int	is_movement_key(int keycode)
{
	return (keycode == 119 || keycode == 87 || keycode == 97 || keycode == 65
		|| keycode == 115 || keycode == 83 || keycode == 100 || keycode == 68);
}

static void	update_position(int keycode, int *new_x, int *new_y)
{
	if (keycode == 119 || keycode == 87)
		(*new_y)--;
	else if (keycode == 97 || keycode == 65)
		(*new_x)--;
	else if (keycode == 115 || keycode == 83)
		(*new_y)++;
	else if (keycode == 100 || keycode == 68)
		(*new_x)++;
}

int	handle_keypress(int keycode, t_game_state *game_state)
{
	int	new_x;
	int	new_y;

	new_x = game_state->player->x;
	new_y = game_state->player->y;
	if (keycode == 65307)
	{
		ft_printf("Game exited by user.\n");
		free_game_state(game_state);
		exit(0);
	}
	else if (is_movement_key(keycode))
	{
		update_position(keycode, &new_x, &new_y);
		ft_printf("Attempting to move to (%d, %d).\n", new_x, new_y);
		process_movement(game_state, new_x, new_y);
		render_map(game_state->graphics, game_state->map,
			game_state->rows, game_state->cols);
	}
	return (0);
}
