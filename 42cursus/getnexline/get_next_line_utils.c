/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:27:12 by si-park           #+#    #+#             */
/*   Updated: 2025/02/25 15:55:24 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 개행 문자가 있는지 확인하는 함수
char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL);
}

// 두 개의 문자열을 이어 붙이는 함수
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ss1;
	char	*dup;

	ss1 = (char *)s1;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(ss1) + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (ss1[i])
	{
		dup[i] = ss1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*cc;
	unsigned int	i;
	unsigned int	s_len;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	cc = malloc(len + 1);
	if (cc == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		cc[i] = s[start + i];
		i++;
	}
	cc[i] = '\0';
	return (cc);
}
