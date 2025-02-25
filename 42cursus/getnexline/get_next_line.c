/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:27:14 by si-park           #+#    #+#             */
/*   Updated: 2025/02/25 15:56:11 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **record)
{
	int		i;
	char	*line;
	char	*new_record;

	i = 0;
	if (!(*record) || !((*record)[0]))
		return (NULL);
	while ((*record)[i] && (*record)[i] != '\n')
		i++;
	if ((*record)[i] == '\n')
		i++;
	line = ft_substr(*record, 0, i);
	if (!line)
		return (NULL);
	new_record = ft_strdup(*record + i);
	free(*record);
	*record = new_record;
	return (line);
}

static int	read_and_append(int fd, char **rec, char *buf)
{
	int		reread;
	char	*temp;

	reread = read(fd, buf, BUFFER_SIZE);
	while (reread > 0)
	{
		buf[reread] = '\0';
		if (!(*rec))
			*rec = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(*rec, buf);
			free(*rec);
			*rec = temp;
		}
		if (ft_strchr(*rec, '\n'))
			break ;
		reread = read(fd, buf, BUFFER_SIZE);
	}
	return (reread);
}

char	*get_next_line(int fd)
{
	static char	*record[1024];
	char		*buf;
	int			reread;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	reread = read_and_append(fd, &record[fd], buf);
	free(buf);
	if (reread < 0)
	{
		if (record[fd])
			free(record[fd]);
		record[fd] = NULL;
		return (NULL);
	}
	if (record[fd] && record[fd][0])
		return (extract_line(&record[fd]));
	if (record[fd])
		free(record[fd]);
	record[fd] = NULL;
	return (NULL);
}
