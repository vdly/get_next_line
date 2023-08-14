/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:52:00 by johii             #+#    #+#             */
/*   Updated: 2023/08/14 00:26:03 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    read_basket(int fd, char *basket)
{
	char	*readbuff;
	int		bytes;
	
	bytes = 0;
	readbuff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_strchr(basket, "\n"))
	{
		bytes = read(fd, readbuff, BUFFER_SIZE);
		if (bytes <= 0)
			break;
		readbuff[bytes] = '\0';
	}
	free (readbuff);
	readbuff = (NULL);
	if (bytes)
		return(NULL);
}

char    extract_apples(char *basket)
{
}

char    after_newline(char *basket)
{
}

char    get_next_line(int fd)
{
    static char	*basket;
    char		*apples;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    basket = read_basket(fd, basket);
    if (!basket)
        return (0);
    apples = extract_apples(basket);
    if (apples == 0)
        basket == 0;
    basket = after_newline(basket);
    return (apples);
}
