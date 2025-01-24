/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:39:44 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/24 12:07:00 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*These are the auxiliary functions that I use:
* 1. Ft_strlen since I use them in these same ones and to measure the size of
* the buffer.
* 2. Ft_strchr to check if the tmp_buffer contains a line break and if what it 
* gives me is NULL, to continue the loop.
* 3. Ft_strdup since I use it to duplicate in these same ones.
* 4. Ft_substr, I use it to get the new line and move the buffer to the next 
* line.
* 5. Ft_strjoin, I use it in the function to join the buffers, but I use it
* inside to join them in it, and with a temporary to release the old buffer.*/

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		ptr[i] = str[i];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len)
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		ptr[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		ptr[s1_len + i] = s2[i];
	ptr[s1_len + s2_len] = '\0';
	return (ptr);
}
