/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:30:39 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 21:30:40 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdio.h>

void	process_movement(t_game_state *game_state, int new_x, int new_y)
{
	move_player(game_state, new_x, new_y);
}

void	draw_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
}

void	render_tile(t_data *data, char tile, int x, int y)
{
	void	*img;

	if (tile == '1')
		img = data->wall_img;
	else if (tile == 'P')
		img = data->player_img;
	else if (tile == 'C')
		img = data->collectible_img;
	else if (tile == 'E')
		img = data->exit_img;
	else
		img = data->blank_img;
	draw_image(data, img, x, y);
}
