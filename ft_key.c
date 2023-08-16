/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 03:20:28 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/12 03:20:28 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key(mlx_key_data_t keycode, void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		ft_exit(game);
	if ((keycode.key == MLX_KEY_UP && keycode.action == MLX_PRESS))
		ft_wkey(game);
	if ((keycode.key == MLX_KEY_DOWN && keycode.action == MLX_PRESS))
		ft_skey(game);
	if ((keycode.key == MLX_KEY_RIGHT && keycode.action == MLX_PRESS))
		ft_dkey(game);
	if ((keycode.key == MLX_KEY_LEFT && keycode.action == MLX_PRESS))
		ft_akey(game);
	if (game->gameoverr > 0)
	{
		ft_printf("\033[0;35mGame end \n\e[0m", game);
		ft_exit(game);
	}
	ft_map_builder(game);
}

void	ft_wkey(t_game *game)
{
	int	i;
	int	u;

	i = ft_calculatori(game);
	u = ft_calculatoru(game);
	if (game->map[i - 1][u] == 'E' && game->max_score == game->score)
	{
		game->gameoverr++;
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
	if (game->map[i - 1][u] != '1' && game->map[i - 1][u] != 'E')
	{
		if (game->map[i - 1][u] == 'C')
			game->score++;
		game->map[i][u] = '0';
		game->map[i - 1][u] = 'P';
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
}

void	ft_skey(t_game *game)
{
	int	i;
	int	u;

	i = ft_calculatori(game);
	u = ft_calculatoru(game);
	if (game->map[i + 1][u] == 'E' && game->max_score == game->score)
	{
		game->gameoverr++;
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
	if (game->map[i + 1][u] != '1' && game->map[i + 1][u] != 'E')
	{
		if (game->map[i + 1][u] == 'C')
			game->score++;
		game->map[i][u] = '0';
		game->map[i + 1][u] = 'P';
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
}

void	ft_dkey(t_game *game)
{
	int	i;
	int	u;

	i = ft_calculatori(game);
	u = ft_calculatoru(game);
	if (game->map[i][u + 1] == 'E' && game->max_score == game->score)
	{
		game->gameoverr++;
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
	if (game->map[i][u + 1] != '1' && game->map[i][u + 1] != 'E')
	{
		if (game->map[i][u + 1] == 'C')
			game->score++;
		game->map[i][u] = '0';
		game->map[i][u + 1] = 'P';
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
}

void	ft_akey(t_game *game)
{
	int	i;
	int	u;

	i = ft_calculatori(game);
	u = ft_calculatoru(game);
	if (game->map[i][u - 1] == 'E' && game->max_score == game->score)
	{
		game->gameoverr++;
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
	if (game->map[i][u - 1] != '1' && game->map[i][u - 1] != 'E')
	{
		if (game->map[i][u - 1] == 'C')
			game->score++;
		game->map[i][u] = '0';
		game->map[i][u - 1] = 'P';
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
}
