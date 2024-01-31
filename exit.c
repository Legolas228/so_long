/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pborrull <pborrull@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:28:28 by pborrull          #+#    #+#             */
/*   Updated: 2023/12/12 10:17:25 by pborrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_map *game)
{
	int	line;

	line = 0;
	if (game->win_p)
		mlx_destroy_window(game->mlx_p, game->win_p);
	free(game->mlx_p);
	while (line < game->height)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

void	flood_fill(t_map *game, int x, int y)
{
	if (y < 0 || x >= game->width || x < 0
		|| y >= game->height || game->map[y][x] == '1'
		|| game->map[y][x] == 'p' || game->map[y][x] == '2'
		|| game->map[y][x] == 'e' || game->map[y][x] == 'c')
		return ;
	if (game->map[y][x] == 'E')
	{
		game->flag2 = 1;
		game->map[y][x] = 'e';
		return ;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'c';
		game->count++;
	}
	if (game->map[y][x] == 'P')
		game->map[y][x] = 'p';
	if (game->map[y][x] == '0')
		game->map[y][x] = '2';
	flood_fill(game, x - 1, y);
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
}

void	char_mov(t_map *game, int x, int y)
{
	if (game->map[y][x] == 'c' || game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_p, game->win_p, game->col,
			x * 32, y * 32);
	if (game->map[y][x] == 'p')
		mlx_put_image_to_window(game->mlx_p, game->win_p, game->player,
			x * 32, y * 32);
	if (game->map[y][x] == 'e')
		mlx_put_image_to_window(game->mlx_p, game->win_p, game->exit,
			x * 32, y * 32);
	if (game->map[y][x] == '2' || game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_p, game->win_p,
			game->floor, x * 32, y * 32);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_p, game->win_p,
			game->wall, x * 32, y * 32);
}

int	right(t_map *game, int x, int y)
{
	x = game->x;
	y = game->y;
	if (game->map[y][x + 1] == '1')
		return (0);
	if (game->flag == 2)
	{
		game->map[y][x++] = 'e';
		game->flag = 0;
	}
	else
		game->map[y][x++] = '2';
	game->x++;
	ft_aux(game, x, y);
	return (1);
}

int	up(t_map *game, int x, int y)
{
	x = game->x;
	y = game->y;
	if (game->map[y - 1][x] == '1')
		return (0);
	if (game->flag == 2)
	{
		game->map[y--][x] = 'e';
		game->flag = 0;
	}
	else
		game->map[y--][x] = '2';
	game->y--;
	ft_aux(game, x, y);
	return (1);
}
