/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:43:52 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/13 19:50:08 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define SIZE 4096

int	ft_strlen(const char *s)
{
	if (!s)
		return (0);
	int	i = 0;
	while (s[i])
		i++;
	return (i);
			
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_slen(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while(s[i] || s[i] == c)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (dstsize <= len_dest)
		return (dstsize + len_src);
	i = len_dest;
	while (i < dstsize - 1 && *src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (len_dest + len_src);
}

char	*get_next_line(int fd)
{
	size_t	bytes_read;
	char	buffer[4096];
	size_t	len;
	size_t	i;
	char	*line;
	
	if (fd == -1)
		return (NULL);
	bytes_read = read(fd, buffer, SIZE);
	while (bytes_read > 0)
	{
		len = ft_slen(buffer, '\n');
		if (len == 0)
			return (NULL);
		line = (char *)malloc(sizeof(char) * len + 1);
		i = ft_strlcat(line, buffer, len);
		bytes_read = read(fd, buffer, SIZE) > 0;
	}
	return (line);
}

#include <stdio.h>
int	main(void)
{
	int	fd = open("ejemplo.txt", O_RDONLY);
	if (fd == -1) {
		write(1, "No se puede", 11);
		return 1;
	}	
	char	*line = get_next_line(fd);
	printf("%s", line);
	printf("%d", SIZE);
	return 0;
}
