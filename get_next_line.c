/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:52:00 by johii             #+#    #+#             */
/*   Updated: 2023/09/06 17:19:47 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_basket(int fd, char *basket)
{
	char	*temp_basket;
	int		bytes_read;

	bytes_read = 0;
	temp_basket = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_basket)
		return (NULL);
	while (!ft_strchr(basket, '\n'))
	{
		bytes_read = read(fd, temp_basket, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		temp_basket[bytes_read] = '\0';
		basket = ft_strjoin(basket, temp_basket);
	}
	free (temp_basket);
	temp_basket = (NULL);
	if (bytes_read == -1)
		return (NULL);
	return (basket);
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

char	*after_newline(char *basket, int i, int j)
{
	char	*extra_apples;

	while (basket[i] && basket[i] != '\n')
		i++;
	if (!basket[i])
	{
		free (basket);
		return (NULL);
	}
	extra_apples = malloc(sizeof(char) * (ft_strlen(basket) - i));
	if (!extra_apples)
	{
		free (basket);
		return (NULL);
	}
	if (basket[i] == '\n')
		i++;
	while (basket[i])
		extra_apples[j++] = basket[i++];
	extra_apples[j] = '\0';
	free (basket);
	return (extra_apples);
}

char	*get_next_line(int fd)
{
	static char	*basket;
	char		*apples;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	basket = read_basket(fd, basket);
	if (!basket)
		return (0);
	apples = extract_apples(basket);
	basket = after_newline(basket, 0, 0);
	return (apples);
}
// #include <stdio.h>
// int main()
// {
// 	char	*test;
// 	int		fd;
// 	int		fd2;

// 	fd = open("text.txt", O_RDONLY);
// 	test = get_next_line(fd);
// 	free(test);
// 	test = get_next_line(fd);
// 	free(test);
// 	test = get_next_line(fd);
// 	free (test);
// 	printf("line!!??: %s\n", test);
// }
