/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:30:44 by si-park           #+#    #+#             */
/*   Updated: 2025/02/23 13:33:25 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	int			s1_len;
	int			s2_len;
	char		*cc;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	cc = malloc(s1_len + s2_len + 1);
	if (cc == NULL)
		return (NULL);
	while (s1[i])
	{
		cc[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		cc[i + j] = s2[j];
		j++;
	}
	cc[i + j] = '\0';
	return (cc);
}
