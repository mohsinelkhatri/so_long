/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:42:24 by melkhatr          #+#    #+#             */
/*   Updated: 2024/11/22 10:26:45 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*f_all(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
	return (NULL);
}

static char	*ex_line(char **str)
{
	char	*line;
	char	*new_buffer;
	ssize_t	index;

	index = ft_strchr(*str);
	if (index >= 0)
	{
		line = ft_substr(*str, 0, index + 1);
		new_buffer = ft_substr(*str, index + 1, ft_strlen(*str) - index - 1);
		if (!line || !new_buffer)
		{
			free(line);
			free(new_buffer);
			return (NULL);
		}
		free(*str);
		*str = new_buffer;
	}
	else
	{
		line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD] = {NULL};
	char		*temp;
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (ft_strchr(buffer[fd]) == -1)
	{
		read_bytes = read(fd, temp, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		temp[read_bytes] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], temp);
		if (!buffer[fd])
			return (NULL);
	}
	free(temp);
	if (!buffer[fd] || *buffer[fd] == '\0')
		return (f_all(&buffer[fd]));
	return (ex_line(&buffer[fd]));
}
// #include <stdio.h>
// int main()
// {
//     int fd1, fd2;
//     char *line1;
//     char *line2;
//     fd1 = open("file1.txt", O_RDONLY);
//     if (fd1 < 0)
//     {
//         return (1);
//     }
//     fd2 = open("file2.txt", O_RDONLY);
//     if (fd2 < 0)
//     {
//         return (1);
//     }
//     while ((line1 = get_next_line(fd1)) != NULL
// || (line2 = get_next_line(fd2)) != NULL)
//     {
//         if (line1)
//         {
//             printf("File1: %s", line1);
//             free(line1);
//         }
//         if (line2)
//         {
//             printf("File2: %s", line2);
//             free(line2);
//         }
//     }
//     close(fd1);
//     close(fd2);
//     return (0);
// }