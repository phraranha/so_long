/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:25:23 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 17:14:57 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	bonus_counter(t_game *game)
{
	char	*counter;

	counter = ft_itoa(game->count);
	mlx_delete_image(game->mlx, game->counter_back);
	if (game->width > 13)
		game->counter_back = mlx_put_string(game->mlx, counter, 86,
				(game->height * IMG_H));
	else
		game->counter_back = mlx_put_string(game->mlx, counter, 9, (game->height
					* IMG_H));
	free(counter);
	counter = NULL;
}

static void	taken_literally(t_game *game)
{
	game->player->instances[0].enabled = 0;
	ft_printf("P was taken literally:(\nYOU LOSE!\n");
	final_cleanup(game);
}

void	update_player_position(t_game *game, int new_y, int new_x)
{
	game->player->instances[0].x = new_x * IMG_W;
	game->player->instances[0].y = new_y * IMG_H;
	game->player_left->instances[0].x = game->player->instances[0].x;
	game->player_left->instances[0].y = game->player->instances[0].y;
	game->player_blink->instances[0].x = game->player->instances[0].x;
	game->player_blink->instances[0].y = game->player->instances[0].y;
	game->player_blink_left->instances[0].x = game->player->instances[0].x;
	game->player_blink_left->instances[0].y = game->player->instances[0].y;
	game->p_pos_y = new_y;
	game->p_pos_x = new_x;
	game->count++;
	bonus_counter(game);
}

void	handle_movement(t_game *game, int new_y, int new_x)
{
	update_player_position(game, new_y, new_x);
	if (game->side == 0)
	{
		game->player_left->instances[0].enabled = 0;
		game->player->instances[0].enabled = 1;
		game->exit->instances[0].enabled = 1;
	}
	if (game->side == 1)
		left_rendering(game);
	if (game->grid[new_y][new_x] == 'C')
	{
		game->c--;
		collectible_rendering(game);
		game->grid[new_y][new_x] = '0';
	}
	if (game->grid[new_y][new_x] == 'E' && game->c == 0)
	{
		ft_printf("P finally escaped from the .ber map.\n");
		final_cleanup(game);
	}
}

void	move_player(t_game *game, int new_y, int new_x)
{
	if (game->grid[new_y][new_x] == '1')
		return ;
	if (game->grid[new_y][new_x] == 'X')
		taken_literally(game);
	else
		handle_movement(game, new_y, new_x);
}
