/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pborrull <pborrull@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:47:24 by pborrull          #+#    #+#             */
/*   Updated: 2024/01/16 09:41:24 by pborrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct map
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		fd;
	int		flag;
	int		flag2;
	int		count;
	int		moves;
	int		tokencount;
	int		tokencatch;	
	int		playercount;
	int		exitcount;
	int		i;
	int		k;
	void	*mlx_p;
	void	*win_p;
	char	**map;
	void	*player;
	void	*col;
	void	*exit;
	void	*floor;
	void	*wall;
}	t_map;

int		map_reading(t_map *game, char **s);
void	error_checker(t_map *game);
int		ft_exit(t_map *game);
void	xpm_to_image(t_map *game);
void	char_mov(t_map *game, int x, int y);
int		deal_key(int key, t_map *game);
void	flood_fill(t_map *game, int x, int y);
int		mouse_hook(t_map *game);
int		right(t_map *game, int x, int y);
int		up(t_map *game, int x, int y);
void	ft_aux(t_map *game, int x, int y);

#endif
