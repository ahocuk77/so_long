/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:44:39 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/07 23:43:26 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *ubm, ...)
{
	va_list		ap;
	int			a;
	const char	*str;

	a = 0;
	str = ft_strdup(ubm);
	if (!str)
		return (0);
	va_start(ap, ubm);
	a = a + ft_input_parser(str, ap);
	va_end(ap);
	free((void *)str);
	return (a);
}
