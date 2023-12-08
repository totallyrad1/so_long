/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:13:34 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/07 03:38:26 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"
 

typedef struct	game
{
	char	**map;
	char	**map2;
	int		height;
	int		width;
	int		movements;
	int		coins;
	void	*mlx;
	void	*mlx_win;
}				t_game_info;

typedef struct	s_assets
{
	void	*wall;
	void	*player;
	void	*coin;
	void	*door;
	void	*floor;
}				t_assets;

// tools
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *s);
int		linelen(char *str);

//parsemap tools
int		validcomponent(char c);
int		doesmapexist(char *map);
char	**read_map(char *map);
int validcomponentscheck(char **check, t_game_info *game, int e, int p);
int 	checkifmaprectangular(char **str);
int 	checkfullwall(char *str);
int 	validcomponent(char c);
int 	surroundedwalls(char **map);
void	flood_fill(t_game_info **game, int i, int j);
int		backtrackingcheck(t_game_info *game);
int		get_i(char **map);
int		get_j(char **map);

// rendering tools
void	put_img(t_game_info *game, char *ptr, int i, int j);
int 	getwidth(char *str);
int 	getheight(char **str);
void 	load_images(void *mlx, t_assets *assets);
void	put_img(t_game_info *game, char *ptr, int j, int i);
void 	maprender(t_game_info *game, t_assets *assets);
void	*freee(char **p);
int		closewindow(t_game_info *game);
void	player_movement(t_game_info *game, int x, int y);
int key_pressed(int key, t_game_info *game);

#endif