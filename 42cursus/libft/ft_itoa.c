/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:02:39 by si-park           #+#    #+#             */
/*   Updated: 2024/11/09 20:21:09 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		length++;
		n /= 10;
	}		
	return (length);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;

	if (n == -2147483648)
		return (strdup("-2147483648"));
	length = count_length(n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		result[--length] = (n % 10) + '0';
		n /= 10;
	}
	if (result[1] == '\0' && length == 1)
		result[0] = '0';
	return (result);
}
