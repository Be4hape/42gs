/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:41:27 by si-park           #+#    #+#             */
/*   Updated: 2024/11/09 19:07:35 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*cc;
	unsigned int	i;
	unsigned int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	cc = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
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
