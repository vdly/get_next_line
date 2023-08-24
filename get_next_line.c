/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:52:00 by johii             #+#    #+#             */
/*   Updated: 2023/08/24 22:52:33 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_basket(int fd, char *basket)
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
		basket = ft_strjoin(basket, readbuff);
	}
	free (readbuff);
	readbuff = (NULL);
	if (bytes == -1)
		return(NULL);
	return(basket);
}

char	*extract_apples(char *basket)
{
	int		i;
    char	*apples;

	i = 0;
	if (!basket || !basket[i])
		return (NULL);
	while (basket[i] != '\n' && basket[i]) 
		i++;
	apples = malloc(sizeof(char) * (i + 2)); 
	if (!apples)
		return (NULL);
	i = 0;
	while (basket[i] != '\n' && basket[i])
	{
		apples[i] = basket[i];
		i++;
	}
	if (basket[i] == '\n')
		apples[i++] = '\n';
	apples[i] = '\0';
	return (apples);
}

char	*after_newline(char *basket)
{
	int     i;
	char    *extra_apples;

	i = 0;
	if (!basket)
		return (NULL);
	while (basket[i] != '\n' && basket[i])
		i++;
	if (!basket[i])
	{
		free(basket);
		return (NULL);
	}
	extra_apple = malloc(sizeof(char) * (ft_strlen(basket) - i));
	if (!extra_apples)
	{
		free(basket);
		return (NULL);
	}
	ft_strcpy(extra_apples[i] && basket [i + 1]);
	free(basket);
	return (extra_apples);
}

char	get_next_line(int fd)
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
