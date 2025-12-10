/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thasampa <thasampa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:22:09 by thasampa          #+#    #+#             */
/*   Updated: 2025/12/10 20:05:24 by thasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//static char	*get_line(char *rest, char *stash, char *line, char *buffer);
static char	*fill_line(int fd, char *rest, char *buffer);
static char	*cut_first_line(char *line);
static char	*get_rest(char *line);

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;

	if (rest == NULL)
		rest = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, rest, buffer);
	rest = get_rest(line);
	line = cut_first_line(line);
	free(buffer);
	buffer = NULL;
	free(rest);
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
			free(buffer);
			free(rest);
			return (NULL);
		}
		tmp = rest;
		buffer[bytes_read] = 0;
		rest = ft_strjoin(tmp, buffer);
		free(tmp);
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

	rest_line = ft_substr(line, (ft_strchr(line, '\n') - line) + 1, ft_strlen(line));
	return (rest_line);
}
