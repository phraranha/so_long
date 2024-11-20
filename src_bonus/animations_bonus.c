/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:46:55 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 17:43:34 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	enemy_spin(void *param)
{
	t_game		*game;
	mlx_image_t	*sprites[4];

	game = (t_game *)param;
	sprites[0] = game->enemy;
	sprites[1] = game->enemy1;
	sprites[2] = game->enemy2;
	sprites[3] = game->enemy3;
	game->x_time = mlx_get_time();
	game->spin_period = 0.09;
	game->spin_index = (int)(game->x_time / game->spin_period) % 4;
	game->sprite_n = 0;
	if (game->x > 0)
	{
		while (game->sprite_n < 4)
		{
			game->inst0 = 0;
			while (game->inst0 < game->x)
				sprites[game->sprite_n]->instances[game->inst0++].enabled = 0;
			game->sprite_n++;
		}
		game->inst1 = 0;
		while (game->inst1 < game->x)
			sprites[game->spin_index]->instances[game->inst1++].enabled = 1;
	}
}

static void	player_blink(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->p_time = mlx_get_time();
	game->blink_period = 0.6;
	game->blink_enabled = (int)(game->p_time / game->blink_period) % 2;
	game->player->instances[0].enabled = 0;
	game->player_left->instances[0].enabled = 0;
	game->player_blink->instances[0].enabled = 0;
	game->player_blink_left->instances[0].enabled = 0;
	if (game->side == 0)
	{
		if (game->blink_enabled == 0)
			game->player_blink->instances[0].enabled = 1;
		else
			game->player->instances[0].enabled = 1;
	}
	else if (game->side == 1)
	{
		if (game->blink_enabled == 0)
			game->player_blink_left->instances[0].enabled = 1;
		else
			game->player_left->instances[0].enabled = 1;
	}
}

void	animations(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	player_blink(game);
	enemy_spin(game);
}
