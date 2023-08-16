/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:11:57 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/07 23:42:44 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_input_parser(const char *str, va_list args)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (str[a])
	{
		if (str[a] != '%')
			b = b + ft_putchar_fd2(str[a], 1);
		else if ((str[a] == '%') && str[a + 1])
		{
			a++;
			if (ft_is_argument(str[a]))
				b = b + ft_formats(str[a], args);
			else
				b = b + ft_putchar_fd2(str[a], 1);
		}
		a++;
	}
	return (b);
}
