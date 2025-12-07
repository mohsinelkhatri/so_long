/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:41:04 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 14:22:05 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error(NULL, "You must enter only one map file");
	game.map = parse_map(av[1]);
	validate_map(game.map);
	start_game(game);
	return (0);
}
