/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:41:01 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 15:22:23 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_str_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	destroy_texture(void *mlx, void **texture)
{
	if (texture && *texture)
	{
		mlx_destroy_image(mlx, *texture);
		*texture = NULL;
	}
}

static void	destroy_all_textures(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	destroy_texture(game->mlx, (void **)&game->txt.b);
	destroy_texture(game->mlx, (void **)&game->txt.w);
	destroy_texture(game->mlx, (void **)&game->txt.c);
	destroy_texture(game->mlx, (void **)&game->txt.pu);
	destroy_texture(game->mlx, (void **)&game->txt.pd);
	destroy_texture(game->mlx, (void **)&game->txt.pl);
	destroy_texture(game->mlx, (void **)&game->txt.pr);
	destroy_texture(game->mlx, (void **)&game->txt.e);
}

void	free_textures(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	destroy_all_textures(game);
}

void	clean(t_game *game, int exit_code)
{
	if (!game)
		exit(exit_code);
	free_textures(game);
	if (game->map)
		ft_free_str_array(game->map);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (exit_code == 1)
		exit(1);
	else if (exit_code == 0)
		exit(0);
	else if (exit_code == 2)
	{
		write(1, "You win :)\n", 11);
		exit(0);
	}
}
