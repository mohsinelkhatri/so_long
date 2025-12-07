/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:46:54 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/04 17:44:38 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/ft_printf/ft_printf.h"
# include "libs/get_next_line/get_next_line.h"
# include "libs/minilibx/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_txt
{
	void	*b;
	void	*w;
	void	*c;
	void	*pu;
	void	*pd;
	void	*pl;
	void	*pr;
	void	*m;
	void	*e;
}			t_txt;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	int		p_pos[2];
	int		e_pos[2];
	int		**m_pos;
	t_txt	txt;
}			t_game;

void		error(char **map, char *msg);
void		free_map(char **map);
size_t		map_width(char *s);
size_t		map_height(char **map);
void		find_coords(char **map, int *p_pos, int *e_pos);
bool		is_all_collected(char **map);
void		free_textures(t_game *game);

char		**parse_map(char *path);
void		validate_map(char **map);
void		check_characters(char **map);
void		check_shape(char **map);
void		check_border(char **map);
void		check_way(char **map);
int			ft_atoi(const char *nptr);
void		clean(t_game *game, int exit_code);
char		**ft_split(char const *s, char c);
int			checking_line(char *str);
char		*get_next_line(int fd);
void		start_game(t_game game);
void		fill_textures(t_game game, char key);
void		move_player(t_game *game, int x_off, int y_off, char key);
int			close_game(t_game *game);

#endif
