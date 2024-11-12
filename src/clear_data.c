/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:08:07 by ariling           #+#    #+#             */
/*   Updated: 2024/11/12 11:18:40 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

static void	destroy_images(t_data *data)
{
	if (data->wall_img)
	{
		mlx_destroy_image(data->mlx, data->wall_img);
		data->wall_img = NULL;
	}
	if (data->player_img)
	{
		mlx_destroy_image(data->mlx, data->player_img);
		data->player_img = NULL;
	}
	if (data->collectible_img)
	{
		mlx_destroy_image(data->mlx, data->collectible_img);
		data->collectible_img = NULL;
	}
	if (data->exit_img)
	{
		mlx_destroy_image(data->mlx, data->exit_img);
		data->exit_img = NULL;
	}
	if (data->blank_img)
	{
		mlx_destroy_image(data->mlx, data->blank_img);
		data->blank_img = NULL;
	}
}

static void	destroy_window_and_mlx(t_data *data)
{
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	destroy_images(data);
	destroy_window_and_mlx(data);
	// free(data);
}

static void	free_map_leek(t_game_state *game_state)
{
	int	i;

	if (!game_state->map)
		return ;
	i = 0;
	while (i < game_state->rows)
	{
		if (game_state->map[i])
		{
			free(game_state->map[i]);
			game_state->map[i] = NULL;
		}
		i++;
	}
	free(game_state->map);
	game_state->map = NULL;
}

void	free_game_state(t_game_state *game_state)
{
	if (!game_state)
		return ;
	if (game_state->player)
	{
		free(game_state->player);
		game_state->player = NULL;
	}
	free_map_leek(game_state);
	if (game_state->graphics)
	{
		free_data(game_state->graphics);
		game_state->graphics = NULL;
	}
	free(game_state);
}
