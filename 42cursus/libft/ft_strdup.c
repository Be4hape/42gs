/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:02:20 by si-park           #+#    #+#             */
/*   Updated: 2024/11/10 14:49:39 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
