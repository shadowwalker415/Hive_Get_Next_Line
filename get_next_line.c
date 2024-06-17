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

char	*read_buffer(int fd, char *buffer)
{
	
}

char *free_mem(char *memory)
{
	free(memory);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*safe;
	char			*buffer;
	char			*temp;
	int				bytes_read;
	
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	temp = "";
	bytes_read = 1;
	string = NULL;
	while (bytes_read != 0 || BUFFER_SIZE < 1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return free_mem(safe);
		buffer[bytes_read]  = '\0';
		safe = ft_strjoin()
	}
	if (bytes_read == 0)
		free(buffer);
	return (0);
}


int main(void)
{
	int fd;
	char *string;
	char *string2;
	
	fd = open("sample.txt", O_RDONLY | O_CREAT);
	if (!fd)
		return (-1);
	string = get_next_line(fd);
	printf("%s\n", string);
	free(string);
	return (0);
}
