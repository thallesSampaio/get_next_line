/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thasampa <thasampa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:28:13 by thasampa          #+#    #+#             */
/*   Updated: 2025/12/11 19:05:00 by thasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 

int main(void)
{
    char *filePath = "file";
    char *line;
    int   fd;

    fd = open(filePath, O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("GNL: %s", line);
        free(line);
    }
	free(line);
}
