/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:00:03 by mel-amma          #+#    #+#             */
/*   Updated: 2022/03/13 15:55:08 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*createbuffer(int fd, char *readingbuffer, char *buffer)
{
	int		ret;
	char	*temp;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, readingbuffer, BUFFER_SIZE);
		if (ret == 0)
			return (buffer);
		else if (ret < 0)
			return (0);
		readingbuffer[ret] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		temp = buffer;
		buffer = ft_strjoin(temp, readingbuffer);
		free(temp);
		temp = 0;
		if (ft_strchr(readingbuffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*splittext(char *text)
{
	char	*buffer;
	int		i;

	i = 0;
	while (text[i] != '\n' && text[i])
		i++;
	buffer = ft_substr(text, i + 1, ft_strlen(text));
	if (buffer[0] == '\0')
	{
		free(buffer);
		return (0);
	}
	text[i + 1] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*readingbuffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	readingbuffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!readingbuffer)
		return (0);
	line = createbuffer(fd, readingbuffer, buffer);
	free(readingbuffer);
	readingbuffer = 0;
	if (!line)
		return (0);
	buffer = splittext(line);
	return (line);
}



hbhhuhu