/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 04:38:47 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/12 04:38:47 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image(t_game *game)
{
	int	b;

	b = 64;
	game->texture->wall = mlx_load_png(
			"./textures/wall.png");
	game->texture->exit = mlx_load_png(
			"./textures/exit.png");
	game->texture->item = mlx_load_png(
			"./textures/item.png");
	game->texture->player = mlx_load_png(
			"./textures/player.png");
	game->texture->space = mlx_load_png(
			"./textures/space.png");
	if (!game->texture->wall || !game->texture->exit
		||!game->texture->item || !game->texture->player
		||!game->texture->space)
	{
		free(game->mlx);
		ft_errorm("\033[0;31mimage load error \n\e[0m", game);
	}
}

int	ft_map_builder(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	while (a < game->height)
	{
		b = 0;
		while (b < game->width)
		{
			if (game->map[a][b] == '1')
				mlx_image_to_window(game->mlx, game->image->wall,
					b * 64, a * 64);
			if (game->map[a][b] == '0')
				mlx_image_to_window(game->mlx, game->image->space,
					b * 64, a * 64);
			if (game->map[a][b] == 'P')
				mlx_image_to_window(game->mlx, game->image->player,
					b * 64, a * 64);
			b++;
		}
		a++;
	}
	ft_map_builder2(game);
	return (0);
}

int	ft_exit(t_game *game)
{
	int	cnt;

	cnt = 0;
	if (game->window)
		mlx_delete_image(game->mlx, game->window);
	if (game->mlx)
		free(game->mlx);
	while (cnt < game->height)
	{
		free(game->map[cnt]);
		cnt++;
	}
	free(game->map);
	exit(EXIT_SUCCESS);
}

void	ft_image_convert(t_game *game, mlx_t *mlx)
{
	game->image->player = mlx_texture_to_image(mlx, game->texture->player);
	game->image->item = mlx_texture_to_image(mlx, game->texture->item);
	game->image->exit = mlx_texture_to_image(mlx, game->texture->exit);
	game->image->space = mlx_texture_to_image(mlx, game->texture->space);
	game->image->wall = mlx_texture_to_image(mlx, game->texture->wall);
	if (!game->image->exit || !game->image->item || !game->image->player
		|| !game->image->space || !game->image->wall)
	{
		mlx_delete_image(mlx, game->image->player);
		mlx_delete_image(mlx, game->image->item);
		mlx_delete_image(mlx, game->image->exit);
		mlx_delete_image(mlx, game->image->space);
		mlx_delete_image(mlx, game->image->wall);
	}
}

int	ft_map_builder2(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	while (a < game->height)
	{
		b = 0;
		while (b < game->width)
		{
			if (game->map[a][b] == 'E')
				mlx_image_to_window(game->mlx, game->image->exit,
					b * 64, a * 64);
			if (game->map[a][b] == 'C')
				mlx_image_to_window(game->mlx, game->image->item,
					b * 64, a * 64);
			b++;
		}
		a++;
	}
	return (0);
}
