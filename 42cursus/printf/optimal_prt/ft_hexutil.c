/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:54:07 by si-park           #+#    #+#             */
/*   Updated: 2025/01/14 21:05:50 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_hex(int is_upper)
{
	if (is_upper)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

int	ft_putnbr_hex(unsigned long num, int is_upper)
{
	int		k;
	int		count_byte;
	char	hex[16];
	char	*c_hex;

	k = 0;
	count_byte = 0;
	c_hex = get_hex(is_upper);
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (num)
	{
		hex[k] = c_hex[num % 16];
		num /= 16;
		k++;
	}
	while (--k >= 0)
	{
		ft_putchar_fd(hex[k], 1);
		count_byte++;
	}
	return (count_byte);
}

int	ft_print_p(void *p)
{
	int	count_byte;

	count_byte = 2;
	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	count_byte += ft_putnbr_hex((unsigned long)p, 0);
	return (count_byte);
}

static unsigned int	count_length(unsigned int n)
{
	unsigned int	length;

	if (n == 0)
		return (1);
	length = 0;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*un_itoa(unsigned int n)
{
	unsigned int	length;
	char			*result;

	length = count_length(n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while (length > 0)
	{
		result[length - 1] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	return (result);
}
