/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:13:34 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/09 13:29:46 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct game
{
	char	**map;
	char	**map2;
	int		h;
	int		w;
	int		movements;
	int		coins;
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*player;
	void	*coin;
	void	*door;
	void	*floor;
}				t_game_info;

// tools
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *s);
int		linelen(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
void	printmovement(t_game_info *game);
char	*ft_itoa(int n);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

//parsemap tools
int		validcomponent(char c);
int		doesmapexist(char *map);
char	**read_map(char *map);
int		validcomponentscheck(char **check, t_game_info *game, int e, int p);
int		checkifmaprectangular(char **str);
int		checkfullwall(char *str);
int		validcomponent(char c);
int		surroundedwalls(char **map);
void	flood_fill(t_game_info **game, int i, int j);
int		backtrackingcheck(t_game_info *game);
int		get_i(char **map);
int		get_j(char **map);
int		checkcomponents(int coins, int e, int p);
void	update_e_and_p(char c, int *e, int *p);

// rendering tools
void	put_img(t_game_info *game, char *ptr, int i, int j);
int		getwidth(char *str);
int		getheight(char **str);
void	load_images(void *mlx, t_game_info *game);
void	put_img(t_game_info *game, char *ptr, int j, int i);
void	maprender(t_game_info *game);
void	*freee(char **p);
int		closewindow(t_game_info *game);
void	player_movement(t_game_info *game, int x, int y, int i);
int		key_pressed(int key, t_game_info *game);

#endif