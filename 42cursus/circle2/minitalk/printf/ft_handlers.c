/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:19:04 by si-park           #+#    #+#             */
/*   Updated: 2025/01/14 21:36:46 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

static int	print_string(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

static int	print_pointer(va_list args)
{
	void	*p;

	p = va_arg(args, void *);
	return (ft_print_p(p));
}

static int	print_decimal(va_list args, char c)
{
	char	*numch;
	int		cnt;
	int		val;

	val = va_arg(args, int);
	if (c == 'u')
		numch = un_itoa((unsigned int)val);
	else
		numch = ft_itoa(val);
	if (!numch)
		return (0);
	ft_putstr_fd(numch, 1);
	cnt = ft_strlen(numch);
	free(numch);
	return (cnt);
}

int	handle_specifier(char c, va_list args)
{
	if (c == 'c')
		return (print_char(args));
	else if (c == 's')
		return (print_string(args));
	else if (c == 'p')
		return (print_pointer(args));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (print_decimal(args, c));
	else if (c == 'x' || c == 'X')
		return (print_hex(args, c));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
