/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 04:38:28 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/12 04:38:28 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_collector(t_game *game)
{
	int	u;
	int	b;

	b = 0;
	u = 0;
	while (game->map[u < game->height])
	{
		if (game->map[u][b] == 'C')
			game->max_score++;
		if (game->map[u][b] == 'E')
			game->gameover++;
		if (game->map[u][b] == 'P')
			game->players++;
		if (b == game->width - 1 && u == game->height - 1)
			break ;
		if (b == game->width - 1)
		{
			b = -1;
			u++;
		}
		b++;
	}
	if (game->players != 1 || game->max_score < 1 || game->gameover != 1)
		ft_errorm("\033[0;31mCheck your map \n\e[0m", game);
}

void	ft_mapcheck(char *maps, t_game *game)
{
	char	*line;
	char	*gnl;
	int		fd;
	char	*tmp;

	gnl = NULL;
	fd = open(maps, O_RDONLY);
	tmp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			break ;
		}
		gnl = ft_strjoin(tmp, line);
		free(tmp);
		tmp = gnl;
		free (line);
		game->height++;
	}
	free(gnl);
	close(fd);
	ft_mapcheck2(game, maps);
}

void	ft_check_wall(t_game *game)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	while (a < game->width)
	{
		if (game->map[0][a] != '1' || game->map[game->height - 1][a] != '1')
			ft_errorm("\033[0;31mCheck your walls \n\e[0m", game);
		a++;
	}
	while (b < game->height)
	{
		if (game->map[b][0] != '1' || game->map[b][game->width - 1] != '1')
			ft_errorm("\033[0;31mCheck your walls \n\e[0m", game);
		b++;
	}
}

void	ft_rectangular_check(t_game *game)
{
	int	x;
	int	y;
	int	size;

	size = ft_strlen(game->map[0]);
	x = 0;
	y = 0;
	while (y < game->height -1)
	{
		x = ft_strlen(game->map[y]);
		if (x != size)
			ft_errorm("\033[0;31mYour map is not rectangular ☹\n\e[0m", game);
		y++;
	}
	if (y == game->height - 1)
	{
		x = ft_strlen(game->map[y]);
		if (x != size - 1)
			ft_errorm("\033[0;31mYour map is not rectangularrr ☹\n\e[0m", game);
	}
	ft_check_wall(game);
}

void	ft_mapcopy(t_game *game, char *maps)
{
	int		i;
	int		fd;

	fd = open(maps, O_RDONLY);
	game->map = malloc((game->height) * sizeof(char *));
	if (!(game->map))
	{
		close(fd);
		ft_errorm("\033[0;31mCopy error \n\e[0m", game);
	}
	i = 0;
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		if (!(game->map[i]))
		{
			close(fd);
			ft_errorm("\033[0;31mCopy error \n\e[0m", game);
		}
		i++;
	}
	close (fd);
}
