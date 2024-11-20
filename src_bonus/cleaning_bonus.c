/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:44:34 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 17:14:43 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	panic_cleanup(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->height)
	{
		free(game->grid[x]);
		game->grid[x] = NULL;
		x++;
	}
	free(game->grid);
	game->grid = NULL;
	free(game->collec);
	game->collec = NULL;
}

void	cleanup(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->height)
	{
		free(game->grid[x]);
		game->grid[x] = NULL;
		x++;
	}
	free(game->grid);
	game->grid = NULL;
}

void	final_cleanup(t_game *game)
{
	cleanup(game);
	free(game->collec);
	game->collec = NULL;
	game->counter_back = NULL;
	mlx_close_window(game->mlx);
}

void	error_function(int i)
{
	if (i == 1)
		ft_printf("Error:\nWrong map file format\n");
	else if (i == 2)
		ft_printf("Error:\nWrong file descriptor\n");
	else if (i == 3)
		ft_printf("Error:\nEmpty map file\n");
	else if (i == 4)
		ft_printf("Error:\nMap is not valid or is not surrounded by borders\n");
	else if (i == 5)
		ft_printf("Error:\nInvalid characters\n");
	else if (i == 6)
		ft_printf("Error:\nInvalid number of characters\n");
	else if (i == 7)
		ft_printf("Error:\nSome collectibles or the exit are not accessible\n");
	else if (i == 8)
		ft_printf("Error:\nMaps is not a rectangle\n");
	exit(1);
}

void	delete_images(t_game *game)
{
	mlx_delete_texture(game->wall_t);
	mlx_delete_texture(game->player_t);
	mlx_delete_texture(game->player_left_t);
	mlx_delete_texture(game->player_blink_t);
	mlx_delete_texture(game->player_blink_left_t);
	mlx_delete_texture(game->collec_t);
	mlx_delete_texture(game->exit_t);
	mlx_delete_texture(game->empty_t);
	mlx_delete_texture(game->back_t);
	mlx_delete_texture(game->back_small_t);
	mlx_delete_texture(game->enemy_t);
	mlx_delete_texture(game->enemy1_t);
	mlx_delete_texture(game->enemy2_t);
	mlx_delete_texture(game->enemy3_t);
}
