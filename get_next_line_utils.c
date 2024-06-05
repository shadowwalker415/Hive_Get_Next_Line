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

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*temp;
	size_t	i;

	temp = (char *)b;
	i = 0;
	while (i < len)
	{
		temp[i] = (char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (count > 0 && size > 0 && count > UINT_MAX / size)
		return (0);
	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	ptr = ft_memset(ptr, 0, total_size);
	return (ptr);
}
