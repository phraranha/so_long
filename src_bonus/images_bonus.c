/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:00:11 by paranha           #+#    #+#             */
/*   Updated: 2024/03/13 16:08:28 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	load_images(t_game *game)
{
	game->wall_t = mlx_load_png("assets/1.png");
	game->player_t = mlx_load_png("assets/P.png");
	game->player_left_t = mlx_load_png("assets/P_left.png");
	game->collec_t = mlx_load_png("assets/C.png");
	game->exit_t = mlx_load_png("assets/E.png");
	game->empty_t = mlx_load_png("assets/0.png");
	game->player_blink_t = mlx_load_png("assets/P_blink.png");
	game->player_blink_left_t = mlx_load_png("assets/P_blink_left.png");
	game->back_t = mlx_load_png("assets/steps.png");
	game->back_small_t = mlx_load_png("assets/pipe.png");
	game->enemy_t = mlx_load_png("assets/backslash.png");
	game->enemy1_t = mlx_load_png("assets/hyphen.png");
	game->enemy2_t = mlx_load_png("assets/slash.png");
	game->enemy3_t = mlx_load_png("assets/pipe.png");
}

void	render_images(t_game *game)
{
	game->wall = mlx_texture_to_image(game->mlx, game->wall_t);
	game->player = mlx_texture_to_image(game->mlx, game->player_t);
	game->player_left = mlx_texture_to_image(game->mlx, game->player_left_t);
	game->player_blink = mlx_texture_to_image(game->mlx, game->player_blink_t);
	game->player_blink_left = mlx_texture_to_image(game->mlx,
			game->player_blink_left_t);
	game->collec->collec = mlx_texture_to_image(game->mlx, game->collec_t);
	game->exit = mlx_texture_to_image(game->mlx, game->exit_t);
	game->empty = mlx_texture_to_image(game->mlx, game->empty_t);
	game->back = mlx_texture_to_image(game->mlx, game->back_t);
	game->back_small = mlx_texture_to_image(game->mlx, game->back_small_t);
	game->enemy = mlx_texture_to_image(game->mlx, game->enemy_t);
	game->enemy1 = mlx_texture_to_image(game->mlx, game->enemy1_t);
	game->enemy2 = mlx_texture_to_image(game->mlx, game->enemy2_t);
	game->enemy3 = mlx_texture_to_image(game->mlx, game->enemy3_t);
	game->counter_back = mlx_new_image(game->mlx, IMG_W, IMG_H);
	delete_images(game);
}

void	put_elements(t_game *game, t_map *map, int x, int y)
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
			else if (game->grid[y][x] == 'X')
				enemy_rendering(game, x, y);
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
	render_images(game);
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
	if (map->width > 13)
		mlx_image_to_window(game->mlx, game->back, 0, (map->height * IMG_H));
	else
		mlx_image_to_window(game->mlx, game->back_small, 0, (map->height
				* IMG_H));
}
