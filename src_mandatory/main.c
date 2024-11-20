/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:08:11 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 17:08:05 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	game_init(t_game *game)
{
	game->collec = (t_collec *)malloc(sizeof(t_collec));
	if (!game->collec)
		exit(1);
	game->collec->pos_x = 0;
	game->collec->pos_y = 0;
	game->width = 0;
	game->height = 0;
	game->e = 0;
	game->p = 0;
	game->c = 0;
	game->collectibles = 0;
	game->p_pos_y = 0;
	game->p_pos_x = 0;
	game->flood_c = 0;
	game->flood_e = 0;
	game->count = 0;
	game->side = 0;
}

int	game_start(t_map *map, char *buf)
{
	t_game	game;

	game_init(&game);
	game.width = map->width;
	game.height = map->height;
	count_epc(&game, buf);
	game.grid = ft_split(buf, '\n');
	path_finder(&game);
	game.grid = ft_split(buf, '\n');
	game.mlx = mlx_init(game.width * IMG_W, game.height * IMG_H, "Terminal",
			false);
	if (!game.mlx)
	{
		ft_printf("Error:\nNo game\n%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	render_map(&game, map);
	mlx_key_hook(game.mlx, &key_hook, &game);
	validate(buf);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	if (game.grid)
		panic_cleanup(&game);
	return (EXIT_SUCCESS);
}

static int	ber_check(char *filename)
{
	int	i;

	i = 0;
	while (filename[i] != '\0')
		i++;
	if (filename[i - 4] != '.' || filename[i - 3] != 'b' || filename[i
			- 2] != 'e' || filename[i - 1] != 'r')
		error_function(1);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Error:\nWrong number of arguments\n");
		return (1);
	}
	ber_check(argv[1]);
	map_check(argv[1]);
	return (0);
}
