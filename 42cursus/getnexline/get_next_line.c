/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:27:14 by si-park           #+#    #+#             */
/*   Updated: 2025/02/23 17:25:33 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

// 문자열 길이를 구하는 함수
size_t	ft_strlen(const char *s)
{
	size_t	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

// 문자열을 복사하는 함수
char	*ft_strdup(const char *s, size_t len)
{
	char	*dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		dup[i] = s[i];
	dup[len] = '\0';
	return (dup);
}

// 문자열을 합치는 함수
char	*ft_strjoin(char *s1, char *s2, size_t len2)
{
	size_t	len1 = ft_strlen(s1);
	char	*joined = (char *)malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	for (size_t i = 0; i < len1; i++)
		joined[i] = s1[i];
	for (size_t j = 0; j < len2; j++)
		joined[len1 + j] = s2[j];
	joined[len1 + len2] = '\0';
	free(s1);  // 기존 문자열 해제
	return (joined);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		buf[BUFFER_SIZE + 1];
	char		*line = NULL;
	ssize_t		reread;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// 파일에서 BUFFER_SIZE 만큼 읽기
	while ((reread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[reread] = '\0';
		buffer = ft_strjoin(buffer, buf, reread);
		if (!buffer)
			return (NULL);

		// 개행 문자 탐색
		for (i = 0; buffer[i]; i++)
		{
			if (buffer[i] == '\n')
			{
				line = ft_strdup(buffer, i + 1);
				char *temp = ft_strdup(buffer + i + 1, ft_strlen(buffer + i + 1));
				free(buffer);
				buffer = temp;
				return (line);
			}
		}
	}

	// 파일 끝에서 마지막 남은 데이터 반환
	if (buffer && *buffer)
	{
		line = ft_strdup(buffer, ft_strlen(buffer));
		free(buffer);
		buffer = NULL;
		return (line);
	}

	free(buffer);
	buffer = NULL;
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}
