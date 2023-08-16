/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:35:28 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/08 00:49:56 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupp(char *str)
{
	char		*cpy;
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (str[len])
		len++;
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoinn(const char *s1, const char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(&str[len1], s2, len1 + len2 + 1);
	return (str);
}

//kopyalar ustune yazar
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t		i;
	size_t		src_length;

	i = 0;
	src_length = 0;
	while (src[src_length])
		src_length++;
	if (destsize <= 0)
		return (src_length);
	while (src[i] && i < destsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_length;
	size_t	s_length;
	char	*substr;

	if (!s)
		return (NULL);
	s_length = 0;
	while (s[s_length])
		s_length++;
	substr_length = s_length - start;
	if (s_length > start)
	{
		if (substr_length > len)
			substr = (char *) malloc(sizeof(char) * (len + 1));
		else
			substr = (char *) malloc(sizeof(char) * (substr_length + 1));
		if (!substr)
			return (NULL);
		ft_strlcpy(substr, &s[start], len + 1);
	}
	else
		substr = ft_strdup("");
	return (substr);
}

char	*gnl_strchr(const char *str, int argument)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char) str[i] == (unsigned char)argument)
			return ((char *) &str[i]);
		i++;
	}
	if (argument == '\0')
		return ((char *) &str[i]);
	return ((void *) 0);
}
