/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:09:02 by si-park           #+#    #+#             */
/*   Updated: 2024/11/10 14:33:23 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (count != 0 && (size > (size_t)-1 / count))
		return (NULL);
	arr = malloc(count * size);
	if (arr == 0)
		return (NULL);
	memset(arr, 0, count * size);
	return (arr);
}
