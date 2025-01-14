/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:02:36 by si-park           #+#    #+#             */
/*   Updated: 2025/01/14 21:37:47 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;

	va_start(args, fmt);
	count = parse_format(fmt, args);
	va_end(args);
	return (count);
}

int	parse_format(const char *fmt, va_list args)
{
	int	count;

	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			count += handle_specifier(*fmt, args);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			count++;
		}
		fmt++;
	}
	return (count);
}

int	print_hex(va_list args, char c)
{
	unsigned int	n;
	int				upper;

	n = va_arg(args, unsigned int);
	if (c == 'x')
		upper = 0;
	else
		upper = 1;
	return (ft_putnbr_hex(n, upper));
}
