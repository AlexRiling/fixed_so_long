/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:17:39 by ariling           #+#    #+#             */
/*   Updated: 2024/11/12 11:14:54 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>  // For size_t
# include "libft.h"   // Include libft's header
# include <mlx.h>     // Include MiniLibX's header

/* Struct Definitions */

typedef struct s_player
{
	int	x;
	int	y;
	int	move_count;
}	t_player;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	void	*blank_img;
}	t_data;

typedef struct s_game_state
{
	t_player	*player;
	t_data		*graphics;
	char		**map;
	int			rows;
	int			cols;
	int			collectibles; // Tracks remaining collectibles
}	t_game_state;

typedef struct s_counts
{
	int	player;
	int	collectibles;
	int	exits;
}	t_counts;

/* Function Prototypes */
void	free_game_state(t_game_state *game_state);
void	free_data(t_data *data);
/* Map Parsing and Validation */
int		validate_map(char **map, int rows, int cols, t_counts *counts);
char	**parse_map(const char *file_path, int *rows, int *cols);
int		is_map_surrounded_by_walls(char **map, int rows, int cols);
int		validate_map_elements(char **map, int rows, int cols);
void	count_elements(char **map, int rows, int cols, t_counts *counts);
void	free_map(char **map);

/* Player Functions */
void	find_player(char **map, t_player *player, int rows, int cols);
void	move_player(t_game_state *game_state, int new_x, int new_y);

/* Graphics Functions */
void	init_window(t_data *data, t_game_state *game_state);
void	load_textures(t_data *data);
void	check_textures(t_data *data);
void	render_map(t_data *data, char **map, int rows, int cols);
void	draw_image(t_data *data, void *img, int x, int y);
void	render_tile(t_data *data, char tile, int x, int y);
int		handle_keypress(int keycode, t_game_state *game_state);
int		handle_close(t_game_state *game_state);
void	process_movement(t_game_state *game_state, int new_x, int new_y);

/* Utility Functions */
char	**ft_split(const char *str, char delimiter);
size_t	ft_strlen(const char *str);
int		check_row_lengths(char **map, int rows, int *cols);
int		count_rows(char **map);

#endif
