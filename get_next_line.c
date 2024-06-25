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

static char *free_memory(char **memory)
{
	if (*memory == NULL)
		return (NULL);
	free(*memory);
	*memory = NULL;
	return (NULL);
}

static char	*read_to_buffer(int fd, char *buffer, char *backup)
{
	int		bytes_read;
	char	*temp_line;

	bytes_read = 1; 
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_memory(&backup));
		else if (bytes_read == 0)
			return (backup);
		buffer[bytes_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		if (!backup)
			return (NULL);
		temp_line = backup;
		backup = ft_strjoin(temp_line, buffer);
		free_memory(&temp_line);
		if (!backup)
			return (free_memory(&backup));
		if (ft_strchr(buffer, '\n'))
			return (backup);
	}
	return (backup);
}

static char *generate_line(char *backup, char *line)
{
	size_t	i;

	i = 0;
	while (backup[i] != '\n' && backup[i])
		i++;
	if (backup[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] != '\n' && backup[i])
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);

}

static char *get_remainder(char *backup)
{
	size_t	i;
	char	*remainder;

	i = 0;
	while (backup[i] != '\n' && backup[i])
		i++;
	if (backup[i] == '\n')
		i++;
	if (backup[i] == '\0')
		return (free_memory(&backup));
	remainder = ft_strdup(&backup[i]);
	if (!remainder)
		return (free_memory(&backup));
	free_memory(&backup);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*buffer;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		if (backup != NULL)
			return (free_memory(&backup));
		return (NULL);
	}
	backup = read_to_buffer(fd, buffer, backup);
	free_memory(&buffer);
	if (!backup)
		return (free_memory(&buffer));
	line = generate_line(backup, line);
	if (!line)
		return (free_memory(&backup));
	backup = get_remainder(backup);
	return (line);
}
