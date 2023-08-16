/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal_format.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:44:43 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/07 23:43:35 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_decimal_format(unsigned int value)
{
	int		a;
	char	*str;

	str = ft_itoa_base(value, "0123456789");
	a = ft_string_format(str);
	free(str);
	return (a);
}
