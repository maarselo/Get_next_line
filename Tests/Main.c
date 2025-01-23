/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:12:40 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/23 17:43:38 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Ponga un archivo.");
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error abriendo el archivo");
        return (1);
    }
    line = get_next_line(fd);
    if (line)
    {
        printf("Primera linea: %s", line);
        free(line);
    }
    printf("\nLeyendo lo demas:\n");
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}

