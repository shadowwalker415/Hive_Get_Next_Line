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
	while (str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*temp_dest;
	char	*temp_src;
	size_t	remainder;
	size_t	src_len;

	temp_dest = (char *)dst;
	temp_src = (char *)src;
	remainder = dstsize;
	src_len = ft_strlen(temp_src);
	while (*temp_src && remainder > 1)
	{
		*(temp_dest++) = *(temp_src++);
		remainder--;
	}
	if (remainder > 0)
		*temp_dest = '\0';
	return (src_len);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*destination;
	size_t	sub_len;

	if (!s)
		return (NULL);
	sub_len = 0;
	destination = NULL;
	if (ft_strlen(s) >= start)
	{
		sub_len = ft_strlen(s + start);
		if (sub_len > len)
			sub_len = len;
	}
	destination = malloc(sub_len + 1);
	if (destination == NULL)
		return (NULL);
	if (sub_len > 0)
		ft_strlcpy(destination, s + start, sub_len + 1);
	else
		destination[sub_len] = 0;
	return (destination);
}
