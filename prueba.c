/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:03:12 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/13 15:20:55 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	buffer[4096];
	int	fd = open("ejemplo.txt", O_RDONLY);
	if (fd == -1){
		write(1, "maricon", 7);
		return 1;
	}
	size_t	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read > 0) {
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
	}
	return 0;
}
