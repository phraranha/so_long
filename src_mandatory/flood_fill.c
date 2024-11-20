/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:08:17 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 17:08:38 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	flood_fill(t_game *game, int x, int y)
{
	if (game->grid[x][y] == '#' || game->grid[x][y] == '1')
		return ;
	if (game->grid[x][y] == 'E')
		game->flood_e++;
	if (game->grid[x][y] == 'C')
		game->flood_c++;
	game->grid[x][y] = '#';
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
}

void	path_finder(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'P')
			{
				flood_fill(game, y, x);
				if (game->flood_c != game->c || game->flood_e != game->e)
				{
					error_function(7);
					cleanup(game);
					exit(1);
				}
				cleanup(game);
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	collectible_rendering(t_game *game)
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
		game->player->instances[0].enabled = 1;
		game->exit->instances[0].enabled = 1;
	}
}

void	move_player(t_game *game, int new_y, int new_x)
{
	if (game->grid[new_y][new_x] == '1')
		return ;
	else
	{
		game->player->instances[0].x = new_x * IMG_W;
		game->player->instances[0].y = new_y * IMG_H;
		game->p_pos_y = new_y;
		game->p_pos_x = new_x;
		game->count++;
		ft_printf("Steps: %d\n", game->count);
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
}
