/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:44:41 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/07 23:43:32 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_string_format(char *str)
{
	int	a;

	a = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
	{
		while (str[a] != '\0')
			a = a + ft_putchar_fd2(str[a], 1);
		return (a);
	}
}
