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
