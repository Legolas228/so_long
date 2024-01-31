/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pborrull <pborrull@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:15:34 by pborrull          #+#    #+#             */
/*   Updated: 2023/12/06 10:50:51 by pborrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graphics_base(t_map *game, int x, int y)
{
	if (game->map[y][x] == '2' || game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_p, game->win_p,
			game->floor, x * 32, y * 32);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_p, game->win_p,
			game->wall, x * 32, y * 32);
}

void	image_to_map(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'c' || game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_p, game->win_p, game->col,
					x * 32, y * 32);
			else if (game->map[y][x] == 'p')
				mlx_put_image_to_window(game->mlx_p, game->win_p, game->player,
					x * 32, y * 32);
			else if (game->map[y][x] == 'e')
				mlx_put_image_to_window(game->mlx_p, game->win_p, game->exit,
					x * 32, y * 32);
			graphics_base(game, x, y);
			x++;
		}
		y++;
	}
}

void	xpm_to_image(t_map *game)
{
	int	i;
	int	j;

	game->player = mlx_xpm_file_to_image(game->mlx_p, "textures/shaq2.xpm",
			&i, &j);
	game->col = mlx_xpm_file_to_image(game->mlx_p, "textures/ball2.xpm",
			&i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx_p, "textures/basket2.xpm",
			&i, &j);
	game->floor = mlx_xpm_file_to_image(game->mlx_p, "textures/wood.xpm",
			&i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx_p, "textures/people.xpm",
			&i, &j);
	if (!game->player || !game->col || !game->exit
		|| !game->floor || !game->wall)
	{
		ft_printf("Error\nWe can't charge the images\n");
		ft_exit(game);
	}
	image_to_map(game);
}
