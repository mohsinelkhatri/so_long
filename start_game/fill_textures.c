/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:40:22 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 17:42:40 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	fill_texture(t_game game, void *txt, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.win, txt, x, y);
}

static void	fill_player_textures(t_game game, char key, int x, int y)
{
	if (key == 'w')
		fill_texture(game, game.txt.pu, x, y);
	if (key == 's')
		fill_texture(game, game.txt.pd, x, y);
	if (key == 'a')
		fill_texture(game, game.txt.pl, x, y);
	if (key == 'd')
		fill_texture(game, game.txt.pr, x, y);
}

void	fill_textures(t_game game, char key)
{
	int	i;
	int	j;

	i = -1;
	while (++i, game.map[i])
	{
		j = -1;
		while (++j, game.map[i][j])
		{
			if (game.map[i][j] == '0')
				fill_texture(game, game.txt.b, j * 50, i * 50);
			if (game.map[i][j] == '1')
				fill_texture(game, game.txt.w, j * 50, i * 50);
			if (game.map[i][j] == 'C')
				fill_texture(game, game.txt.c, j * 50, i * 50);
			if (game.map[i][j] == 'P')
				fill_player_textures(game, key, j * 50, i * 50);
			if (game.map[i][j] == 'E')
				fill_texture(game, game.txt.e, j * 50, i * 50);
		}
	}
}
