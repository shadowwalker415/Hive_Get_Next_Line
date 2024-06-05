/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:15:59 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/29 19:13:50 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *free_memory(char *mem_to_free)
{
	free(mem_to_free);
	return (0);
}


char	*copy_line(const char *start)
{
	char	*str_duplicate;
	int 	i;
	size_t	len;
	
	len = 0;
	i = 0;
	len = ft_strlen(start);
	str_duplicate = (char *)ft_calloc(len + 2, 1);
	if (str_duplicate == NULL)
		return (NULL);
	while (start[i] != '\n')
	{
		str_duplicate[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		str_duplicate[i] = '\n';
	return (str_duplicate);
}

char *get_next_line(int fd)
{
	char			*line;
	char			*start;
	static char		buffer[BUFFER_SIZE];
	static int		bytes_read = -1;

	if (fd < 0 || BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	start = &buffer[bytes_read + 1];
	while (bytes_read != 0 && bytes_read <= BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (buffer[bytes_read + 1] == '\n')
			break;
	}
	line = copy_line(start);
	if (line == NULL)
		return free_memory(line);
	return (line);
}

int main(void)
{
	int fd;
	char *string;
	char *string2;
	
	fd = open("sample.txt", O_RDONLY | O_CREAT, 777);
	if (!fd)
		return (-1);
	string = get_next_line(fd);
	string2 = get_next_line(fd);
	printf("%s", string);
	printf("%s", string2);
	return (0);
}
