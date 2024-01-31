/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pborrull <pborrull@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:49:07 by pborrull          #+#    #+#             */
/*   Updated: 2023/12/12 10:19:44 by pborrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	correct_walls(t_map *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->height && game->map[y][0] == '1'
			&& game->map[y][game->width - 1] == '1')
		y++;
	while (x < game->width && game->map[0][x] == '1'
			&& game->map[game->height - 1][x] == '1')
		x++;
	if (x + 1 < game->width || y + 1 < game->height)
	{
		ft_printf("Error\nThe ball is out of the court!\n");
		ft_exit(game);
	}
}

void	non_correct(t_map *game)
{
	if (game->playercount == 0 || game->playercount > 1
		|| game->exitcount == 0 || game->exitcount > 1 || game->tokencount < 1)
	{
		ft_printf("Error\n");
		if (game->tokencount == 0)
			ft_printf("Where is the ball?\n");
		if (game->playercount == 0)
			ft_printf("Where is Shaq?\n");
		else if (game->playercount > 1)
			ft_printf("There are two Shaqs. How is posible?\n");
		if (game->exitcount == 0)
			ft_printf("Where is the basket?\n");
		else if (game->exitcount > 1)
			ft_printf("Alright then... where do I need to score?\n");
		ft_exit(game);
	}
}

void	correct_char(t_map *game, int y, int x)
{
	if (game->map[y][x] == 'C')
		game->tokencount++;
	else if (game->map[y][x] == 'P')
	{
		game->playercount++;
		game->x = x;
		game->y = y;
	}
	else if (game->map[y][x] == 'E')
		game->exitcount++;
	else if (game->map[y][x] != '0' && game->map[y][x] != '1')
	{
		ft_printf("Error\nWe can't play in a pool.\nSorry:(!\n");
		ft_exit(game);
	}
}

void	map_check(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height - 1)
	{
		x = 0;
		while (x < game->width)
		{
			correct_char(game, y, x);
			x++;
		}
		y++;
	}
	non_correct(game);
}

void	error_checker(t_map *game)
{
	int	i;

	i = 0;
	correct_walls(game);
	map_check(game);
	flood_fill(game, game->x, game->y);
	if (game->flag2 != 1)
	{
		ft_printf("Exit\nWe cannot play with people in the court!\n");
		ft_exit(game);
	}
	if (game->count != game->tokencount)
	{
		ft_printf("Exit\nOh no! Kobe takes the ball!\n");
		ft_exit(game);
	}
}
