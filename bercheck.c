/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bercheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 04:34:00 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/12 04:34:00 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_bercheck(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] != 'r' || map[len - 2] != 'e'
		|| map[len - 3] != 'b' || map[len - 4] != '.')
	{
		return (0);
	}
	else
		return (1);
}

int	ft_calculatoru(t_game *game)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (game->map[i][u] != 'P')
	{
		if (u == game->width)
		{
			u = 0;
			i++;
		}
		if (i == game->height -1 && u == game->width - 1)
			break ;
		u++;
	}
	return (u);
}

void	ft_check_collector2(t_game *game)
{
	int	u;
	int	b;

	b = 0;
	u = 0;
	while (game->map[u < game->height])
	{
		if (game->map[u][b] != '1' && game->map[u][b] != '0'
			&& game->map[u][b] != 'E'
			&& game->map[u][b] != 'C' && game->map[u][b] != 'P' )
			ft_errorm("Check your map", game);
		if (b == game->width - 1 && u == game->height - 1)
		{
			break ;
		}
		if (b == game->width - 1)
		{
			b = -1;
			u++;
		}
		b++ ;
	}
}

int	ft_calculatori(t_game *game)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (game->map[i][u] != 'P')
	{
		if (u == game->width)
		{
			u = 0;
			i++;
		}
		if (i == game->height -1 && u == game->width - 1)
			break ;
		u++;
	}
	return (i);
}

void	ft_close(void *param)
{
	t_game	*game;

	game = param;
	exit(EXIT_SUCCESS);
}
