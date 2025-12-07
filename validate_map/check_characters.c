/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:40:49 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 15:31:50 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	check_character(char ch, size_t *p, size_t *e, size_t *c)
{
	if (ch == 'P')
		(*p)++;
	else if (ch == 'E')
		(*e)++;
	else if (ch == 'C')
		(*c)++;
	else if (ch != '0' && ch != '1')
		return (false);
	return (true);
}

void	check_characters(char **map)
{
	size_t	players;
	size_t	exits;
	size_t	collectibles;
	int		i;
	int		j;

	players = 0;
	exits = 0;
	collectibles = 0;
	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
			if (!check_character(map[i][j], &players, &exits, &collectibles))
				error(map, "The map contains invalid characters");
	}
	if (players != 1)
		error(map, "The map has wrong number of players");
	if (exits != 1)
		error(map, "The map has wrong number of exits");
	if (collectibles < 1)
		error(map, "The map has wrong number of collectibles");
}
