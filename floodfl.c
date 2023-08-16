/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 04:48:18 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/12 07:47:11 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfl(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	game->copycollect = game->max_score;
	while (x < game->height)
	{
		y = 0;
		while (game->mapcopy[x][y])
		{
			if (game->mapcopy[x][y] == 'P' &&
				(arrplayer (game, x + 1, y, x - 1) == 1 ||
				arrplayer1 (game, x, y - 1, y + 1) == 1))
				x = 0;
			if (game->mapcopy[x][y] == 'E')
				exitcheck(game, x, y);
			y++;
		}
		x++;
	}
	if (game->copycollect == 0 && game->muz == 1)
	{
		game->zort = 1;
	}
}

int	arrplayer(t_game *game, int x, int y, int xe)
{
	if ((game->mapcopy[x][y] == 'C' || game->mapcopy[x][y] == '0') ||
		(game->mapcopy[xe][y] == 'C' || game->mapcopy[xe][y] == '0'))
	{
		if (game->mapcopy[x][y] == 'C')
			game->copycollect--;
		if (game->mapcopy[x][y] == 'C' || game->mapcopy[x][y] == '0')
			game->mapcopy[x][y] = 'P';
		if (game->mapcopy[xe][y] == 'C')
			game->copycollect--;
		if (game->mapcopy[xe][y] == 'C' || game->mapcopy[xe][y] == '0')
			game->mapcopy[xe][y] = 'P';
	}
	else
		return (0);
	return (1);
}

int	arrplayer1(t_game *game, int x, int y, int ye)
{
	if ((game->mapcopy[x][y] == 'C' || game->mapcopy[x][y] == '0') ||
		(game->mapcopy[x][ye] == 'C' || game->mapcopy[x][ye] == '0'))
	{
		if (game->mapcopy[x][y] == 'C')
			game->copycollect--;
		if (game->mapcopy[x][y] == 'C' || game->mapcopy[x][y] == '0')
			game->mapcopy[x][y] = 'P';
		if (game->mapcopy[x][ye] == 'C')
			game->copycollect--;
		if (game->mapcopy[x][ye] == 'C' || game->mapcopy[x][ye] == '0')
			game->mapcopy[x][ye] = 'P';
	}
	else
		return (0);
	return (1);
}

void	exitcheck(t_game *game, int x, int y)
{
	if ((game->mapcopy[x][y + 1] == 'P')
		|| (game->mapcopy[x][y - 1] == 'P')
		|| (game->mapcopy[x - 1][y] == 'P')
		|| (game->mapcopy[x + 1][y] == 'P'))
	{
		game->muz = 1;
	}
}
