/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thasampa <thasampa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:22:36 by thasampa          #+#    #+#             */
/*   Updated: 2025/12/16 16:00:27 by thasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == 0)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc((total_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*dest;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) - start) < len)
		size = ft_strlen(s) - start;
	else if (ft_strlen(s) <= start || len == 0)
		size = 0;
	else
		size = len;
	dest = (char *) malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
