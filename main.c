/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thasampa <thasampa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:28:13 by thasampa          #+#    #+#             */
/*   Updated: 2025/12/10 19:07:11 by thasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 

int	main(void)
{
	char	*filePath = "file";
	char	*print;
	//char	*print2;
	int	fd;
	
	fd = open(filePath, O_RDONLY);
	print = get_next_line(fd);
	//print2 = get_next_line(fd);
	printf("GNL: %s\n", print);
	//printf("GNL: %s\n", print2);
	free(print);
	//free(print2);
}
