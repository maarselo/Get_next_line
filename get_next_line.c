/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:05:49 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/18 22:41:45 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *ptr)
{
	free(ptr);
}

char	*ft_fnextline(char *buffer)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen(buffer);
	while (buffer[i] && buffer[i] != '\n')
	       i++;
	if (buffer[i] == '\n')
		i++;
	ptr = ft_substr(buffer, i, len - i);
	if (!ptr)
		return (NULL);	
	ft_free(buffer);
	return (ptr);
}

char	*ft_findline(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	       i++;
	if (buffer[i] == '\n')
		i++;
	return (ft_substr(buffer, 0, i));
}

char	*ft_read(int fd , char	*buffer)
{
	char	*tmp_buffer;
	char	*tmp;
	ssize_t	bytes_read;

	tmp_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(tmp_buffer, '\n'))
	{
		bytes_read = read(fd, tmp_buffer,BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free(tmp_buffer);
			return (NULL);
		}
		tmp_buffer[bytes_read] = 0;
		tmp = ft_strjoin(buffer, tmp_buffer);
		if (!tmp)
		{
			ft_free(tmp_buffer);
			return (NULL);
		}
		ft_free(buffer);
		buffer = tmp;
	}
	ft_free(tmp_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_findline(buffer);
	if (!line)
		return (NULL);
	buffer = ft_fnextline(buffer);
	return (line);
}

#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY); 
    if (fd == -1)
    {
        perror("Error abriendo el archivo");
        return 1;
    }
    char *line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        free(line); 
        line = get_next_line(fd); 
    }

    close(fd); 
    return 0;
}
