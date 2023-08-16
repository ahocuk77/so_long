/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 04:38:07 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/12 04:38:07 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_errorm(char *str, t_game *game)
{
	int	cnt;

	cnt = 0;
	while (cnt < game->height)
	{
		free(game->map[cnt]);
		cnt++;
	}
	ft_printf("\033[0;31mERROR! \n\e[0m");
	ft_printf(str);
	exit(EXIT_FAILURE);
}

void	ft_mapcopyy(t_game *game, char *maps)
{
	int		i;
	int		fd;

	fd = open(maps, O_RDONLY);
	game->mapcopy = malloc((game->height) * sizeof(char *));
	if (!(game->map))
	{
		close(fd);
		ft_errorm("\033[0;31mCopy error \n\e[0m", game);
	}
	i = 0;
	while (i < game->height)
	{
		game->mapcopy[i] = get_next_line(fd);
		if (!(game->mapcopy[i]))
		{
			close(fd);
			ft_errorm("\033[0;31mCopy error \n\e[0m", game);
		}
		i++;
	}
	close (fd);
}
