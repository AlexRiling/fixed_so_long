/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:16:09 by ariling           #+#    #+#             */
/*   Updated: 2024/11/12 11:07:41 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

int	handle_close(t_game_state *game_state)
{
	ft_printf("Game closed by user.\n");
	free_game_state(game_state);
	exit(0);
}
