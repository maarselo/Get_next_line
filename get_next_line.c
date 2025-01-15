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

#include "get_next_line.h"

int	ft_checkn(char *str)
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
char	*get_next_line(int fd)
{
	//static char	*buffer;
	char	*buffer_tmp;
	size_t	bytes_read;

	if (fd = -1 || BUFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer_tmp)
		return(NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_checkn(buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);

	}

}
