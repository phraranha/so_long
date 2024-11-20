/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:17:22 by paranha           #+#    #+#             */
/*   Updated: 2024/03/13 14:31:31 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_images(t_game *game)
{
	game->wall_t = mlx_load_png("assets/1.png");
	game->player_t = mlx_load_png("assets/P.png");
	game->collec_t = mlx_load_png("assets/C.png");
	game->exit_t = mlx_load_png("assets/E.png");
	game->empty_t = mlx_load_png("assets/0.png");
	game->wall = mlx_texture_to_image(game->mlx, game->wall_t);
	mlx_delete_texture(game->wall_t);
	game->player = mlx_texture_to_image(game->mlx, game->player_t);
	mlx_delete_texture(game->player_t);
	game->collec->collec = mlx_texture_to_image(game->mlx, game->collec_t);
	mlx_delete_texture(game->collec_t);
	game->exit = mlx_texture_to_image(game->mlx, game->exit_t);
	mlx_delete_texture(game->exit_t);
	game->empty = mlx_texture_to_image(game->mlx, game->empty_t);
	mlx_delete_texture(game->empty_t);
}

static void	player_rendering(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->player, (x * IMG_W), (y * IMG_H));
	game->p_pos_y = y;
	game->p_pos_x = x;
}

static void	put_elements(t_game *game, t_map *map, int x, int y)
{
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (game->grid[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wall, (x * IMG_W), (y
						* IMG_H));
			else if (game->grid[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit, (x * IMG_W), (y
						* IMG_H));
			else if (game->grid[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->collec->collec, (x
						* IMG_W), (y * IMG_H));
			x++;
		}
		y++;
	}
}

void	put_player(t_game *game, t_map *map, int x, int y)
{
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (game->grid[y][x] == 'P')
			{
				player_rendering(game, x, y);
				break ;
			}
			x++;
		}
		if (game->grid[y][x] == 'P')
			break ;
		y++;
	}
}

void	render_map(t_game *game, t_map *map)
{
	int	y;
	int	x;

	load_images(game);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_image_to_window(game->mlx, game->empty, (x * IMG_W), (y
					* IMG_H));
			x++;
		}
		y++;
	}
	y = 0;
	put_elements(game, map, x, y);
	put_player(game, map, x, y);
}
