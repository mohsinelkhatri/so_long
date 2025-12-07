/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:32:48 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 14:21:18 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_border(char **map)
{
	size_t	width;
	size_t	height;
	size_t	i;
	size_t	j;

	width = map_width(map[0]) - 1;
	height = map_height(map) - 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == height || j == 0 || j == width)
				if (map[i][j] != '1')
					error(map, "The map must be surrounded by walls");
			j++;
		}
		i++;
	}
}

int	checking_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[0] != '1')
		return (1);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != '1' && str[i] != 'E' && str[i] != 'P' && str[i] != 'C'
			&& str[i] != '0')
			return (1);
		i++;
	}
	if (i == 0 || str[i - 1] != '1')
		return (1);
	return (0);
}
