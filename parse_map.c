/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:41:06 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 15:25:35 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_newline_errors(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
	{
		write(2, "Error: newline detected\n", 24);
		free(str);
		exit(1);
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			write(2, "Error: newline detected\n", 24);
			free(str);
			exit(1);
		}
		i++;
	}
}

static char	*read_map(int fd)
{
	char	*str;
	char	*line;

	str = get_next_line(fd);
	if (!str)
		error(NULL, "Map file is empty");
	line = get_next_line(fd);
	while (line)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}
	check_newline_errors(str);
	return (str);
}

char	**parse_map(char *path)
{
	char	**map;
	char	*map_str;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error(NULL, "Wrong file path");
	map_str = read_map(fd);
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}
