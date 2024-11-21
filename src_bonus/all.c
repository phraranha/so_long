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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:17:35 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 17:17:24 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
	game->x = 0;
	game->collectibles = 0;
	game->p_pos_y = 0;
	game->p_pos_x = 0;
	game->e_pos_y = 0;
	game->e_pos_x = 0;
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
	game.mlx = mlx_init(game.width * IMG_W, (game.height * IMG_H) + IMG_H,
			"Terminal", false);
	if (!game.mlx)
	{
		ft_printf("Error:\nNo game\n%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	render_map(&game, map);
	mlx_key_hook(game.mlx, &key_hook, &game);
	validate(buf);
	mlx_loop_hook(game.mlx, &animations, &game);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:10:03 by paranha           #+#    #+#             */
/*   Updated: 2024/03/18 19:38:19 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static int	map_borders(t_map *map, char *buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (buf[i + k] != '\0' && j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if ((buf[i + k] != '1' && j == 0) || (buf[i + k] != '1'
					&& j == (map->height - 1)) || buf[k] != '1'
				|| buf[(map->width - 1) + k] != '1')
				error_function(4);
			i++;
		}
		j++;
		k += (map->width + 1);
	}
	return (0);
}

static void	map_rectangle(t_map *map, char *buf)
{
	map->height = get_height(buf);
	map->width = (map->total_char - map->height) / map->height;
	map->rectangle = (map->total_char - map->height) % (map->width
			* map->height);
	if (map->rectangle != 0)
		error_function(8);
}

static int	map_max_size(t_map *map)
{
	if (map->height > 57 || map->width > 213)
		error_function(4);
	return (0);
}

static void	map_init(t_map *map)
{
	map->total_char = 0;
	map->width = 0;
	map->height = 0;
	map->rectangle = 0;
}

int	map_check(char *filename)
{
	int		fd;
	int		i;
	t_map	map;
	char	buf[BUFFER_MAX + 1];

	i = 0;
	while (i < BUFFER_MAX + 1)
		buf[i++] = '\0';
	map_init(&map);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_function(2);
	map.total_char = read(fd, buf, BUFFER_MAX);
	buf[map.total_char] = '\0';
	close(fd);
	if (buf[0] == '\0')
		error_function(3);
	validate(buf);
	map_rectangle(&map, buf);
	map_borders(&map, buf);
	map_max_size(&map);
	check_epc(buf);
	game_start(&map, buf);
	return (0);
}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:13:40 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 16:09:07 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	count_epc(t_game *game, char *buf)
{
	int	i;

	game->c = 0;
	game->e = 0;
	game->p = 0;
	game->x = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == 'C')
			game->c++;
		if (buf[i] == 'E')
			game->e++;
		if (buf[i] == 'P')
			game->p++;
		if (buf[i] == 'X')
			game->x++;
		i++;
	}
	game->collectibles = game->c;
}

int	get_height(char *buf)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			height++;
		i++;
	}
	return (height);
}

int	check_epc(char *buf)
{
	int	i;
	int	exit;
	int	collectible;
	int	player;

	i = 0;
	exit = 0;
	collectible = 0;
	player = 0;
	while (buf[i])
	{
		if (buf[i] == 'E')
			exit++;
		if (buf[i] == 'C')
			collectible++;
		if (buf[i] == 'P')
			player++;
		i++;
	}
	if (exit != 1 || player != 1 || collectible < 1)
		error_function(6);
	return (0);
}

int	validate(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '0' || buf[i] == '1' || buf[i] == 'E' || buf[i] == 'P'
			|| buf[i] == 'C' || buf[i] == '\n' || buf[i] == 'X')
			i++;
		else
			error_function(5);
	}
	return (0);
}
