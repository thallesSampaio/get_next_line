/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thasampa <thasampa@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:22:09 by thasampa          #+#    #+#             */
/*   Updated: 2025/12/01 14:11:34 by thasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;

	if (stash == NULL)
		stash = ft_strdup("");
	else
		buffer = ft_strdup(stash);
	while (read(fd, buffer, 1) > 0)
	{
		ft_strjoin(buffer, stash);
	}
	printf("%d bytes read!\n", bytesRead);
	printf("File Contents: %s\n", buffer);
}

int	main(void)
{
	char	*filePath = "file";

	int	fd = open(filePath, O_RDONLY);
	printf("%s", get_next_line(fd));
}
