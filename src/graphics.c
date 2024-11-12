/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:26:30 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 22:24:15 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

static void	load_texture(t_data *data, void **img_ptr, char *path)
{
	int	width;
	int	height;

	*img_ptr = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (!*img_ptr)
	{
		ft_printf("Failed to load texture: %s\n", path);
		exit(1);
	}
}

void	load_textures(t_data *data)
{
	load_texture(data, (void **)&data->wall_img, "textures/wall.xpm");
	load_texture(data, (void **)&data->player_img, "textures/player.xpm");
	load_texture(data, (void **)&data->collectible_img,
		"textures/collectible.xpm");
	load_texture(data, (void **)&data->exit_img, "textures/exit.xpm");
	load_texture(data, (void **)&data->blank_img, "textures/blank.xpm");
}

void	check_textures(t_data *data)
{
	if (!data->wall_img || !data->player_img || !data->collectible_img
		|| !data->exit_img || !data->blank_img)
	{
		ft_printf("One or more textures failed to load.\n");
		exit(1);
	}
}

void	render_map(t_data *data, char **map, int rows, int cols)
{
	int	x;
	int	y;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			render_tile(data, map[y][x], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	init_window(t_data *data, t_game_state *game_state)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Failed to initialize MLX.\n");
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, game_state->cols * 64,
			game_state->rows * 64, "So Long");
	if (!data->win)
	{
		ft_printf("Failed to create window.\n");
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	load_textures(data);
	check_textures(data);
	render_map(data, game_state->map, game_state->rows, game_state->cols);
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, game_state);
	mlx_hook(data->win, 17, 0L, handle_close, game_state);
	mlx_loop(data->mlx);
}
