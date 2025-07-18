/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:25:34 by si-park           #+#    #+#             */
/*   Updated: 2025/01/14 20:47:15 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long num, int is_upper)
{
	char	c_hex_lower[] = "0123456789abcdef";
	char	c_hex_upper[] = "0123456789ABCDEF";
	char	hex[16];
	int		k = 0;
	char	*c_hex;
	int     count_byte = 0;

	if (is_upper)
		c_hex = c_hex_upper;
	else
		c_hex = c_hex_lower;

	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}

	while (num > 0)
	{
		hex[k++] = c_hex[num % 16];
		num /= 16;
	}

	while (--k >= 0)
	{
		ft_putchar_fd(hex[k], 1);
		count_byte++;
	}

	return count_byte;
}

int ft_print_p(void *p)
{
	int count_byte = 2;

	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	count_byte += ft_putnbr_hex((unsigned long)p, 0);

	return count_byte;
}

static unsigned int	count_length(unsigned int n)
{
	unsigned int	length;

	if (n == 0)
		return (1);
	length = 0;
	while (n > 0)
	{
		n /= 10;
		length++;
	}		
	return (length);
}

char	*un_itoa(unsigned int n)
{
	char	*result;
	unsigned int	length;

	length = count_length(n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while (length > 0)
	{
		result[--length] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
