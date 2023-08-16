/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:43:42 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/07 23:42:36 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negative(int *value)
{
	int	b;

	b = 0;
	if (*value == INT_MIN)
	{
		b = 1;
		ft_putchar_fd2('-', 1);
		ft_putchar_fd2('2', 1);
		*value = 147483648;
		b++;
	}
	else if (*value < 0)
	{
		ft_putchar_fd2('-', 1);
		*value *= -1;
		b++;
	}
	return (b);
}

int	ft_decimal_format(int value)
{
	int		a;
	char	*str;

	a = ft_negative(&value);
	str = ft_itoa_base(value, "0123456789");
	a = a + ft_string_format(str);
	free (str);
	return (a);
}
