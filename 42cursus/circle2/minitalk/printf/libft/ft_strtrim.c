/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:19:11 by si-park           #+#    #+#             */
/*   Updated: 2024/11/11 16:13:30 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		start;
	size_t		end;
	char		*trimmed_str;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && is_in_set(s1[start], (char *)set))
		start++;
	while (end >= start && is_in_set(s1[end], (char *)set))
		end--;
	trimmed_str = (char *)malloc(end - start + 2);
	if (trimmed_str == NULL)
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		trimmed_str[i] = s1[start + i];
		i++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
