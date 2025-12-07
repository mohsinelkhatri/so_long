/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:40:30 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 17:42:40 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_coords(char **map, int *p_pos, int *e_pos)
{
	int	i;
	int	j;

	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
		{
			if (map[i][j] == 'P' && p_pos)
			{
				p_pos[0] = i;
				p_pos[1] = j;
			}
			if (map[i][j] == 'E' && e_pos)
			{
				e_pos[0] = i;
				e_pos[1] = j;
			}
		}
	}
}
