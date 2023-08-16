/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 06:13:01 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/12 06:13:01 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_image
{
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*item;
	mlx_image_t	*wall;
	mlx_image_t	*space;
}	t_image;

typedef struct s_texture
{
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*item;
	mlx_texture_t	*wall;
	mlx_texture_t	*space;
}	t_texture;

typedef struct s_game {
	char		**map;
	mlx_t		*mlx;
	void		*window;
	int			width;
	int			height;
	int			players;
	t_texture	*texture;
	int			gameover;
	int			gameoverr;
	int			steps;
	t_image		*image;
	int			score;
	int			max_score;
	int			copycollect;
	char		**mapcopy;
	int			zort;
	int			muz;
	int			u;
	int			b;
}				t_game;

void	second_part(char *map, t_game *game);
void	ft_mlx_start(t_game *game);
void	ft_data(t_game *game);
void	ft_image(t_game *map);
int		ft_map_builder(t_game *game);
void	img_dsp(t_game *game, int y, int x);
int		ft_exit(t_game *game);
void	ft_check_collector(t_game *game);
void	ft_mapcheck(char *maps, t_game *game);
void	ft_check_wall(t_game *game);
void	ft_rectangular_check(t_game *game);
void	ft_key(mlx_key_data_t keycode, void *param);
void	ft_errorm(char *Str, t_game *game);
int		ft_bercheck(char *map);
void	ft_wkey(t_game *map);
void	ft_skey(t_game *map);
void	ft_dkey(t_game *map);
void	ft_akey(t_game *map);
void	ft_mapcopy(t_game *game, char *maps);
void	ft_image_convert(t_game *game, mlx_t *mlx);
void	floodfl(t_game *game);
int		arrplayer(t_game *game, int x, int y, int xe);
void	exitcheck(t_game *game, int x, int y);
void	ft_mapcopyy(t_game *game, char *maps);
int		arrplayer1(t_game *game, int x, int y, int ye);
void	ft_close(void *param);
int		ft_calculatori(t_game *game);
int		ft_calculatoru(t_game *game);
int		map_in_check(t_game *game);
void	ft_check_collector2(t_game *game);
void	ft_mapcheck2(t_game *game, char *maps);
int		ft_map_builder2(t_game *game);
#endif