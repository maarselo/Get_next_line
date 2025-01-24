/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainBonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:35:34 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/24 13:25:13 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//This is the main for testing the bonus of the project
#include <fcntl.h>
#include <stdio.h>
#include "../get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	if (argc != 3)
	{
		printf("Seleccione dos archivos");
		return (1);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error abriendo los archivos");
		if (fd1 >= 0)
			close(fd1);
		if (fd2 >= 0)
			close(fd2);
		return (1);
	}
	printf("Leyendo las primeras lineas:\n");
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	if (line1)
	{
		printf("Archivo 1: %s", line1);
		free(line1);
	}
	if (line2)
	{
		printf("Archivo 2: %s", line2);
		free(line2);
	}
	printf("\nLeyendo todo el archivo 1:\n");
	while ((line1 = get_next_line(fd1)))
	{
		printf("%s", line1);
		free(line1);
	}
	printf("\nLeyendo todo el archivo 2:\n");
	while ((line2 = get_next_line(fd2)))
	{
		printf("%s", line2);
		free(line2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
