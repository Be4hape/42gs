/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:06:43 by si-park           #+#    #+#             */
/*   Updated: 2025/01/14 21:39:46 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *fmt, ...);
int		parse_format(const char *fmt, va_list args);
int		handle_specifier(char c, va_list args);
int		print_hex(va_list args, char c);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
int		ft_putnbr_hex(unsigned long num, int is_upper);
int		ft_print_p(void *p);
char	*ft_itoa(int n);
char	*un_itoa(unsigned int n);

#endif
