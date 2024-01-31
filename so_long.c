/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pborrull <pborrull@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:00:12 by pborrull          #+#    #+#             */
/*   Updated: 2023/12/19 14:21:45 by pborrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	game;

	game.mlx_p = NULL;
	game.win_p = NULL;
	if (argc != 2)
	{
		ft_printf("Error\nI need to play, help me!\n");
		return (0);
	}
	ft_bzero(&game, sizeof(t_map));
	map_reading(&game, argv);
	if (game.width > 78 || game.height > 43)
	{
		ft_printf("Error\nThe court is too large.\n");
		return (0);
	}
	error_checker(&game);
	game.mlx_p = mlx_init();
	game.win_p = mlx_new_window(game.mlx_p, game.width * 32,
			game.height * 32, "so_long");
	xpm_to_image(&game);
	mlx_key_hook(game.win_p, deal_key, (void *)&game);
	mlx_hook(game.win_p, 17, 0, mouse_hook, (void *)&game);
	mlx_loop(game.mlx_p);
}
