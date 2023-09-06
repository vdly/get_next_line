/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:39:00 by johii             #+#    #+#             */
/*   Updated: 2023/09/06 16:36:25 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (ptr && *ptr)
	{		
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (c == 0)
		return (ptr);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
	{
		free (s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free (s1);
	s1 = NULL;
	return (join);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		i++;
	}
	return (i);
}
