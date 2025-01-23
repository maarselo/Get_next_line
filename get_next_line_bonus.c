/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:39:01 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/23 16:04:37 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_buffjoin(char **buffer, char *tmp_buffer)
{
	char	*tmp;

	if (!buffer || !tmp_buffer)
		return ;
	tmp = *buffer;
	*buffer = ft_strjoin(*buffer, tmp_buffer);
	free(tmp);
}

static char	*ft_getline(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (ft_substr(buffer, 0, i));
}

static void	ft_nextline(char **buffer)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	if (!*buffer)
		return ;
	i = 0;
	tmp = *buffer;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	len = ft_strlen(*buffer);
	*buffer = ft_substr(*buffer, i, len - i);
	free(tmp);
}

static void	ft_read(int fd, char **buffer)
{
	ssize_t	bytes_read;
	char	*tmp_buffer;

	tmp_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buffer)
		return ;
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(tmp_buffer, '\n'))
	{
		bytes_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(tmp_buffer);
			return ;
		}
		tmp_buffer[bytes_read] = '\0';
		ft_buffjoin(buffer, tmp_buffer);
		if (!*buffer)
		{
			free(tmp_buffer);
			return ;
		}
	}
	free(tmp_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(fd, &buffer[fd]);
	if (!buffer[fd] || !*buffer[fd])
	{
		free(buffer[fd]);
		return (NULL);
	}
	line = ft_getline(buffer[fd]);
	if (!line)
		free(buffer[fd]);
	ft_nextline(&buffer[fd]);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1 = open("test1.txt", O_RDONLY); 
    int fd2 = open("test2.txt", O_RDONLY); 
    int fd3 = open("test3.txt", O_RDONLY); 
    if (fd == -1)
    {
        perror("Error abriendo el archivo");
        return 1;
    }
    char *line1 = get_next_line(fd1);
    char *line2 = get_next_line(fd2);
    char *line3 = get_next_line(fd3);
	    printf("%s", line1);
	    printf("%s", line2);
	    printf("%s", line3);
	    fflush(stdout);
    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    line3 = get_next_line(fd3);
	    printf("%s", line1);
	    printf("%s", line2);
	    printf("%s", line3);
	    fflush(stdout);
    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    line3 = get_next_line(fd3);
	    printf("%s", line1);
	    printf("%s", line2);
	    printf("%s", line3);

    while (line != NULL)
    {
	    printf("%s", line);
	    free(line); 
	    line = get_next_line(fd); 
    }
    //close(fd); 
    return 0;
}*/
