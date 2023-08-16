/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:14:00 by ahocuk            #+#    #+#             */
/*   Updated: 2023/08/08 00:50:16 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pt_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

int	read_line(int fd, char **buffer, char **backup, char **line)
{
	int		bytread;
	char	*temp;

	bytread = 1;
	while (!gnl_strchr(*backup, '\n') && bytread)
	{
		bytread = read(fd, *buffer, BUFFER_SIZE);
		if (bytread < 0)
			free(buffer);
		(*buffer)[bytread] = '\0';
		temp = *backup;
		*backup = ft_strjoinn(temp, *buffer);
		free (temp);
	}
	pt_free(buffer);
	*backup = ft_down_line(backup, line);
	if (!(**line))
		pt_free(line);
	return (bytread);
}

char	*ft_down_line(char **backup, char **line)
{
	char	*new_backup;
	int		i;

	i = 0;
	new_backup = NULL;
	while (*(*backup + i) != '\n' && *(*backup + i) != '\0')
		i++;
	if (*(*backup + i) == '\n')
	{
		i++;
		*line = ft_substr(*backup, 0, i);
		new_backup = ft_strdupp(*backup + i);
	}
	else
		*line = ft_strdupp(*backup);
	pt_free(backup);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	static char	*buffer_b = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free (buffer);
		return (NULL);
	}
	if (!buffer_b)
		buffer_b = ft_strdupp("");
	if (!read_line(fd, &buffer, &buffer_b, &line) && !line)
		return (NULL);
	return (line);
}
