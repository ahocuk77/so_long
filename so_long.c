/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 04:38:36 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/12 04:38:36 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_data(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->steps = 0;
	game->score = 0;
	game->max_score = 0;
	game->width = 0;
	game->height = 0;
	game->players = 0;
	game->gameover = 0;
	game->gameoverr = 0;
	game->copycollect = 0;
	game->zort = 0;
	game->muz = 0;
	game->u = 0;
	game->b = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_data(&game);
	if (argc != 2)
	{
		ft_errorm("ERROR", &game);
	}
	second_part(argv[1], &game);
	return (0);
}

void	ft_mapcheck2(t_game *game, char *maps)
{
	int	c;

	ft_mapcopy(game, maps);
	ft_mapcopyy(game, maps);
	c = ft_strlen(game->map[0]) - 1;
	game->width = c;
	ft_rectangular_check(game);
	ft_check_collector(game);
	ft_check_collector2(game);
}

void	second_part(char *map, t_game *game)
{
	if (!ft_bercheck(map))
		ft_errorm("zort", game);
	ft_mapcheck(map, game);
	floodfl(game);
	if (game->zort == 1)
		ft_mlx_start(game);
	else
		ft_errorm("Player or item or exit are blocked!", game);
}

void	ft_mlx_start(t_game *game)
{
	game->mlx = mlx_init(game->width * 64, game->height * 64,
			"Zort", true);
	game->image = malloc(sizeof(t_image));
	game->texture = malloc(sizeof(t_texture));
	ft_image(game);
	ft_image_convert(game, game->mlx);
	ft_map_builder(game);
	mlx_close_hook(game->mlx, ft_close, game);
	mlx_key_hook(game->mlx, ft_key, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game->image);
	free(game->texture);
	free(game->mlx);
	free(game);
}
