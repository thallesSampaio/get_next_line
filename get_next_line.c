/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thasampa <thasampa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:22:09 by thasampa          #+#    #+#             */
/*   Updated: 2025/12/01 18:32:18 by thasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			bytesRead;

	if (stash == NULL)
		stash = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(stash, '\n'))
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if (bytesRead <= 0)
			break;
		buffer[bytesRead] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*filePath = "file";

	int	fd = open(filePath, O_RDONLY);
	printf("%s", get_next_line(fd));
}
