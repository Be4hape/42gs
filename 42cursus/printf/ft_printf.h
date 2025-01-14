/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:06:43 by si-park           #+#    #+#             */
/*   Updated: 2025/01/14 17:14:30 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "./libft/libft.h"

int ft_printf(const char *str, ...);
int	ft_putnbr_hex(unsigned long num, int is_upper);
int ft_print_p(void *p);
char	*un_itoa(unsigned int n);

#endif