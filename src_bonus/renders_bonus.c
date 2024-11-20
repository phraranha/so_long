/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:03:30 by paranha           #+#    #+#             */
/*   Updated: 2024/03/18 18:11:08 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	enemy_rendering(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->enemy, (x * IMG_W), (y * IMG_H));
	mlx_image_to_window(game->mlx, game->enemy1, (x * IMG_W), (y * IMG_H));
	mlx_image_to_window(game->mlx, game->enemy2, (x * IMG_W), (y * IMG_H));
	mlx_image_to_window(game->mlx, game->enemy3, (x * IMG_W), (y * IMG_H));
	game->enemy1->instances[0].enabled = 0;
	game->enemy2->instances[0].enabled = 0;
	game->enemy3->instances[0].enabled = 0;
}

void	player_rendering(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->player, (x * IMG_W), (y * IMG_H));
	mlx_image_to_window(game->mlx, game->player_left, (x * IMG_W), (y * IMG_H));
	mlx_image_to_window(game->mlx, game->player_blink, (x * IMG_W), (y
			* IMG_H));
	mlx_image_to_window(game->mlx, game->player_blink_left, (x * IMG_W), (y
			* IMG_H));
	game->player_left->instances[0].enabled = 0;
	game->player_blink->instances[0].enabled = 0;
	game->player_blink_left->instances[0].enabled = 0;
	game->p_pos_y = y;
	game->p_pos_x = x;
}

void	left_rendering(t_game *game)
{
	if (game->side == 1)
	{
		game->player->instances[0].enabled = 0;
		game->player_left->instances[0].enabled = 1;
		game->exit->instances[0].enabled = 1;
	}
}

void	collectible_rendering(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->collectibles)
	{
		if (game->collec->collec->instances[i].x == game->player->instances[0].x
			&& game->collec->collec->instances[i].y == game
			->player->instances[0].y)
			game->collec->collec->instances[i].enabled = 0;
		i++;
	}
	if (game->c == 0)
	{
		game->player->instances[0].enabled = 0;
		game->exit->instances[0].enabled = 1;
	}
}
