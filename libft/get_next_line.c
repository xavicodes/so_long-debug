/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:23:06 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/08/27 17:43:10 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*grab_rest(char *buffer)
{
	char	*next_line;
	size_t	end;
	size_t	i;

	end = 0;
	i = 0;
	while (buffer[end] && buffer[end] != '\n')
		end++;
	if (buffer[end] == '\n')
		end++;
	next_line = malloc((ft_strlen_gnl(buffer) - end + 1) * sizeof(char));
	if (!next_line)
		return (free(buffer), NULL);
	while (buffer[end + i])
	{
		next_line[i] = buffer[end + i];
		i++;
	}
	next_line[i] = '\0';
	if (!next_line[0])
		return (free(buffer), free(next_line), NULL);
	return (free(buffer), next_line);
}

static char	*grab_line(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = malloc(sizeof(char) * ft_strlen_gnl(buffer) + 1);
	if (!temp)
	{
		return (NULL);
	}
	while (buffer[i] != '\n' && buffer[i] != '\0')
		temp[i++] = buffer[j++];
	if (buffer[i] == '\n')
	{
		temp[i] = buffer[j];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

static char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	bytes = 1;
	while (bytes > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			str = ft_strjoin_gnl(str, buffer);
		}
	}
	free(buffer);
	if (bytes == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = grab_line(buffer);
	buffer = grab_rest(buffer);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("result %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
*/