/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:16:04 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/29 19:13:56 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	temp = malloc(sizeof(char) * len + 1);
	if (!temp)
		return (0);
	while (i < len)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_str;

	if (s1 == NULL)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	char	character;
	char	*temp;

	temp = (char *)s;
	character = c;
	while (*temp)
	{
		if (*temp == character)
			return (temp);
		temp++;
	}
	if (character == *temp)
		return (temp);
	return (0);
}

