/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thasampa <thasampa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:22:09 by thasampa          #+#    #+#             */
/*   Updated: 2025/12/16 16:39:58 by thasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_line(int fd, char *rest, char *buffer);
static char	*cut_first_line(char *line);
static char	*get_rest(char *line);

char	*get_next_line(int fd)
{
	static char	*rest[MAX_FD];
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(rest[fd]);
		free(buffer);
		buffer = NULL;
		rest[fd] = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line(fd, rest[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	rest[fd] = get_rest(line);
	line = cut_first_line(line);
	return (line);
}

char	*fill_line(int fd, char *rest, char *buffer)
{
	char	*tmp;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(rest);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (rest == NULL)
			rest = ft_strdup("");
		tmp = rest;
		rest = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(rest, '\n'))
			break ;
	}
	return (rest);
}

static char	*cut_first_line(char *line)
{
	int		line_end;
	char	*line_cuted;

	line_end = (ft_strchr(line, '\n') - line + 1);
	line_cuted = ft_substr(line, 0, line_end);
	free(line);
	return (line_cuted);
}

static char	*get_rest(char *line)
{
	char	*rest_line;

	rest_line = ft_substr(line,
			(ft_strchr(line, '\n') - line) + 1,
			ft_strlen(line));
	if (*rest_line == 0)
	{
		free(rest_line);
		rest_line = NULL;
		return (rest_line);
	}
	return (rest_line);
}
