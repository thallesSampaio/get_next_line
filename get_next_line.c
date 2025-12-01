/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thasampa <thasampa@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:22:09 by thasampa          #+#    #+#             */
/*   Updated: 2025/12/01 12:34:19 by thasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[1024];
	int		bytesRead;

	bytesRead = read(fd, buffer, 1024);
	printf("%d bytes read!\n", bytesRead);
	printf("File Contents: %s\n", buffer);
}

int	main(void)
{
	char	*filePath = "file";

	int	fd = open(filePath, O_RDONLY);
}
