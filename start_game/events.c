/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:40:25 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 17:43:55 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	display_moves(t_game *game, int moves)
{
	(void)game;
	ft_printf("Moves: %d\n", moves);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->txt.b);
	mlx_destroy_image(game->mlx, game->txt.w);
	mlx_destroy_image(game->mlx, game->txt.c);
	mlx_destroy_image(game->mlx, game->txt.pu);
	mlx_destroy_image(game->mlx, game->txt.pd);
	mlx_destroy_image(game->mlx, game->txt.pl);
	mlx_destroy_image(game->mlx, game->txt.pr);
	mlx_destroy_image(game->mlx, game->txt.e);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	exit(0);
}

void	handle_exit(t_game *game, int new_row, int new_col, int moves)
{
	if (new_row == game->e_pos[0] && new_col == game->e_pos[1])
	{
		if (is_all_collected(game->map))
		{
			display_moves(game, moves);
			ft_printf("You Win !\n");
			close_game(game);
		}
	}
}

void	move_player(t_game *game, int x_off, int y_off, char key)
{
	static int	moves = 0;
	int			new_row;
	int			new_col;

	new_row = game->p_pos[0] + x_off;
	new_col = game->p_pos[1] + y_off;
	if (game->map[new_row][new_col] == '1')
		return ;
	moves++;
	if (game->map)
		game->map[new_row][new_col] = 'P';
	handle_exit(game, new_row, new_col, moves);
	if (game->p_pos[0] == game->e_pos[0] && game->p_pos[1] == game->e_pos[1])
		game->map[game->p_pos[0]][game->p_pos[1]] = 'E';
	else
		game->map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->p_pos[0] = new_row;
	game->p_pos[1] = new_col;
	fill_textures(*game, key);
	display_moves(game, moves);
}
