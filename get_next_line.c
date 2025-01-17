/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:05:49 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/17 16:39:30 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
/*
char	*ft_findline(char *buffer)
{

}*/


void	ft_free(char *ptr)
{
	free(ptr);
}

char	*ft_buffjoin(char *buffer, char *tmp_buffer)
{
	char	*tmp;
	
	if (!tmp_buffer)
		return (NULL);
	tmp = ft_strjoin(buffer, tmp_buffer);
	if (!tmp)
		return (NULL);
	ft_free(tmp_buffer);
	return (tmp);
}

char	*ft_read(int fd, char *buffer)
{
	size_t	bytes_read;
	char	*tmp_buffer;	
	
	bytes_read = 1;
	tmp_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp_buffer, BUFFER_SIZE);
		tmp_buffer[bytes_read] = '\0';
		buffer = ft_buffjoin(buffer, tmp_buffer);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	//char	*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	/*line = ft_find_line(buffer);
	if (!line)
		return (NULL);
	//buffer = ft_find_next_line(buffer);
	return (*/
	return (buffer);
}

#include <stdio.h>

int	main(void)
{
	int	fd = open("ejemplo.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	printf("%s", line);
	return 0;
}
