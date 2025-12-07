/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:40:17 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 15:22:17 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_textures(t_game *game)
{
	game->txt.b = mlx_xpm_file_to_image(game->mlx, "textures/0.xpm", &(game->w),
			&(game->h));
	game->txt.w = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm", &(game->w),
			&(game->h));
	game->txt.c = mlx_xpm_file_to_image(game->mlx, "textures/c.xpm", &(game->w),
			&(game->h));
	game->txt.pu = mlx_xpm_file_to_image(game->mlx, "textures/pu.xpm",
			&(game->w), &(game->h));
	game->txt.pd = mlx_xpm_file_to_image(game->mlx, "textures/pd.xpm",
			&(game->w), &(game->h));
	game->txt.pl = mlx_xpm_file_to_image(game->mlx, "textures/pl.xpm",
			&(game->w), &(game->h));
	game->txt.pr = mlx_xpm_file_to_image(game->mlx, "textures/pr.xpm",
			&(game->w), &(game->h));
	game->txt.e = mlx_xpm_file_to_image(game->mlx, "textures/e.xpm", &(game->w),
			&(game->h));
	if (!game->txt.b || !game->txt.w || !game->txt.c || !game->txt.pu
		|| !game->txt.pd || !game->txt.pl || !game->txt.pr
		|| !game->txt.e)
	{
		write(2, "Error: Failed to load one or more textures\n", 44);
		clean(game, 1);
	}
}

int	handle_key_events(int keycode, t_game *game)
{
	if (keycode == 119)
		move_player(game, -1, 0, 'w');
	if (keycode == 115)
		move_player(game, 1, 0, 's');
	if (keycode == 97)
		move_player(game, 0, -1, 'a');
	if (keycode == 100)
		move_player(game, 0, 1, 'd');
	if (keycode == 65307)
		close_game(game);
	return (0);
}

void	start_game(t_game game)
{
	game.mlx = mlx_init();
	if (!game.mlx)
		clean(&game, 1);
	game.w = map_width(game.map[0]);
	game.h = map_height(game.map);
	game.win = mlx_new_window(game.mlx, game.w * 50, game.h * 50, "so_long");
	if (!game.win)
		clean(&game, 1);
	find_coords(game.map, game.p_pos, game.e_pos);
	init_textures(&game);
	fill_textures(game, 'w');
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_key_hook(game.win, handle_key_events, &game);
	mlx_loop(game.mlx);
}
