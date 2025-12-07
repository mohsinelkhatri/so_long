/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_collected.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:40:39 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 17:42:40 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_all_collected(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j] != '\0')
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (false);
	}
	return (true);
}
