/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:43:52 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/15 18:46:43 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*He conseguido entender variable estatica, que cuadn ola llaman las funciones se guarda su resultado,
 * y hemos copiado la primera linea del buffer size en un ezpacio de memroia dinamico y devolver*/
#include "get_next_line.h"

static int	ft_checkn(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_checklen(char const *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);

}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	size_t	bytes_read;
	size_t	len;
	char	*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		len = ft_checklen(buffer);
		line = ft_substr(buffer, 0, len);
		if (ft_checkn(buffer))
			break;
	}
	return (line);
}

#include <stdio.h>

int	main(void)
{
	int	fd = open("ejemplo.txt", O_RDONLY);
	if (fd == -1) {
		puts("No se puede abrir");
		return 1;
	
	}
	char	*ptr = get_next_line(fd);
	printf("%s", ptr);
	return 0;
}
