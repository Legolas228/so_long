/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pborrull <pborrull@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:28:57 by pborrull          #+#    #+#             */
/*   Updated: 2023/12/07 12:37:14 by pborrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_aux(t_map *game, int x, int y)
{
	if (game->map[y][x] == 'c' || game->map[y][x] == 'C')
	{
		game->tokencatch++;
		game->map[y][x] = '2';
	}
	if (game->map[y][x] == 'e' && game->tokencatch == game->tokencount)
	{
		game->moves++;
		ft_printf("You have made %i moves.\n", game->moves);
		ft_printf("Congratulations, you win the match!\n");
		ft_exit(game);
	}
	else if (game->map[y][x] == 'e' && game->tokencatch != game->tokencount)
		game->flag = 2;
	game->map[y][x] = 'p';
	char_mov(game, x - 1, y);
	char_mov(game, x + 1, y);
	char_mov(game, x, y - 1);
	char_mov(game, x, y + 1);
	char_mov(game, x, y);
	game->moves++;
}

int	down(t_map *game, int key, int x, int y)
{
	x = game->x;
	y = game->y;
	if (key == 1 || key == 125)
	{
		if (game->map[y + 1][x] == '1')
			return (0);
		if (game->flag == 2)
		{
			game->map[y++][x] = 'e';
			game->flag = 0;
		}
		else
			game->map[y++][x] = '2';
		game->y++;
	}
	ft_aux(game, x, y);
	return (1);
}

int	left(t_map *game, int key, int x, int y)
{
	x = game->x;
	y = game->y;
	if (key == 0 || key == 123)
	{
		if (game->map[y][x - 1] == '1')
			return (0);
		if (game->flag == 2)
		{
			game->map[y][x--] = 'e';
			game->flag = 0;
		}
		else
			game->map[y][x--] = '2';
		game->x--;
	}
	ft_aux(game, x, y);
	return (1);
}

int	deal_key(int key, t_map *game)
{
	int	good;
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	good = 0;
	if (key == 53)
	{
		ft_printf("The match has end.\nAre you scared?\n");
		ft_exit(game);
		return (0);
	}
	if (key == 0 || key == 123)
		good = left(game, key, x, y);
	if (key == 2 || key == 124)
		good = right(game, x, y);
	if (key == 13 || key == 126)
		good = up(game, x, y);
	if (key == 1 || key == 125)
		good = down(game, key, x, y);
	if (good == 1)
		ft_printf("You have made %i moves.\n", game->moves);
	return (0);
}

int	mouse_hook(t_map *game)
{
	ft_printf("The match has end.\nAre you scared?\n");
	ft_exit(game);
	return (0);
}
