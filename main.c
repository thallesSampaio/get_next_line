/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thasampa <thasampa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:28:13 by thasampa          #+#    #+#             */
/*   Updated: 2025/12/16 15:22:21 by thasampa         ###   ########.fr       */
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
}
