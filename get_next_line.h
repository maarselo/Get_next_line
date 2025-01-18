/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:51:01 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/18 22:05:02 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *get_next_line(int fd);

#endif
