/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:40:54 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 17:42:40 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(char **map, int height, int y, int x)
{
	int	width;

	width = map_width(map[0]);
	if (y < 0 || y >= height || x < 0 || x >= width || map[y][x] == '1'
		|| map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, height, y - 1, x);
	flood_fill(map, height, y + 1, x);
	flood_fill(map, height, y, x - 1);
	flood_fill(map, height, y, x + 1);
}

static char	**duplicate_map(char **map)
{
	char	**map_cpy;
	int		i;

	map_cpy = malloc(sizeof(char *) * (map_height(map) + 1));
	if (!map_cpy)
		return (NULL);
	map_cpy[map_height(map)] = NULL;
	i = -1;
	while (++i, map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
		{
			free_map(map_cpy);
			return (NULL);
		}
	}
	return (map_cpy);
}

void	check_way(char **map)
{
	char	**map_cpy;
	int		p_pos[2];
	size_t	height;

	height = map_height(map);
	map_cpy = duplicate_map(map);
	if (!map_cpy)
		error(map, "Allocation failed.");
	find_coords(map_cpy, p_pos, NULL);
	flood_fill(map_cpy, height, p_pos[0], p_pos[1]);
	if (!is_all_collected(map_cpy))
	{
		free_map(map_cpy);
		error(map, "Map is not finishable.");
	}
	free_map(map_cpy);
}
