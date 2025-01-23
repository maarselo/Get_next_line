/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:39:11 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/23 18:47:16 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Primero, protegemos de inclusiones dobles, y si en caso no nos defines BUFFER
 *SIZE nos encargamos de definirlo nosotros, y cerramos ambos condicionales.
 *Incluimos las libreria de malloc y free, y la de read. Y ponemos los 
 *prototipos de las funciones auxiliares y la del proyecto*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

#endif
