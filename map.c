/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pborrull <pborrull@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:41:25 by pborrull          #+#    #+#             */
/*   Updated: 2023/12/29 10:50:20 by pborrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calc_width(char *s, t_map *game)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
		i--;
	if (game->width && game->width != i)
	{
		ft_printf("Error\nWhy the walls are there?\n");
		ft_exit(game);
	}
	return (i);
}

int	add_lines(t_map *game, char *line)
{
	char	**temp;
	int		i;

	i = 0;
	game->height++;
	temp = (char **)malloc((game->height + 1) * sizeof(char *));
	if (!temp)
		ft_exit(game);
	temp[game->height] = NULL;
	while (i < game->height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	map_reading(t_map *game, char **s)
{
	char	*line;

	game->i = 0;
	game->fd = open (s[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		add_lines (game, line);
	}
	close (game->fd);
	if (!game->map)
	{
		ft_printf("Error\nI need to found a court for dunk!\n");
		ft_exit(game);
	}
	while (game->map[game->i])
		game->width = calc_width(game->map[game->i++], game);
	return (1);
}
