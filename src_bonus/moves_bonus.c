/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:48:55 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 17:10:57 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	move_up(t_game *game)
{
	int	new_y;
	int	new_x;

	new_y = game->p_pos_y - 1;
	new_x = game->p_pos_x;
	if (new_y >= 0)
		move_player(game, new_y, new_x);
}

static void	move_down(t_game *game)
{
	int	new_y;
	int	new_x;

	new_y = game->p_pos_y + 1;
	new_x = game->p_pos_x;
	if (new_y < game->height)
		move_player(game, new_y, new_x);
}

static void	move_left(t_game *game)
{
	int	new_y;
	int	new_x;

	new_y = game->p_pos_y;
	new_x = game->p_pos_x - 1;
	game->side = 1;
	if (new_x >= 0)
		move_player(game, new_y, new_x);
}

static void	move_right(t_game *game)
{
	int	new_y;
	int	new_x;

	new_y = game->p_pos_y;
	new_x = game->p_pos_x + 1;
	game->side = 0;
	if (new_x < game->width)
		move_player(game, new_y, new_x);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		final_cleanup(game);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_K)
		&& keydata.action == MLX_PRESS)
		move_up(game);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_J)
		&& keydata.action == MLX_PRESS)
		move_down(game);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_H)
		&& keydata.action == MLX_PRESS)
		move_left(game);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_L)
		&& keydata.action == MLX_PRESS)
		move_right(game);
}
