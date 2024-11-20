/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:26:15 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 17:12:58 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	flood_fill(t_game *game, int x, int y)
{
	if (game->grid[x][y] == '#' || game->grid[x][y] == '1'
		|| game->grid[x][y] == 'X')
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
