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
