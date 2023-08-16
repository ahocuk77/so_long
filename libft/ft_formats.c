/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:43:44 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/07 23:42:39 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(int c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_char_format(va_arg(args, int));
	else if (c == 's')
		i = ft_string_format(va_arg(args, char *));
	else if (c == 'p')
		i = ft_pointer_format(va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		i = ft_decimal_format(va_arg(args, int));
	else if (c == 'u')
		i = ft_unsigned_decimal_format(va_arg(args, unsigned long));
	else if (c == 'x')
		i = ft_hexadecimal_format(va_arg(args, unsigned long));
	else if (c == 'X')
		i = ft_upper_case_hexadecimal_format(va_arg(args, unsigned long));
	else if (c == '%')
		i = ft_percent_format(c);
	return (i);
}
