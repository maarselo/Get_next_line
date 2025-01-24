/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:39:11 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/24 12:01:44 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*First, we protect against double inclusions, and if you do not define BUFFER
* SIZE we will define it ourselves, and we close both conditionals.
* We include the malloc and free libraries, and the read one. And we put the
* prototypes of the auxiliary functions and the project one*/

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
