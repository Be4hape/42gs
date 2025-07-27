/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_saveNcheck2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:19:39 by si-park           #+#    #+#             */
/*   Updated: 2025/07/27 19:19:19 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	parse_sign(const char *s, int i, int *sign)
{
	*sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			*sign = -1;
		i++;
	}
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (-1);
	return (i);
}

static int	parse_digit(t_node **head, const char *s, int i, int sign)
{
	int			d;
	int			int_max;
	int			int_min;
	long long	acc;

	acc = 0;
	int_max = 2147483647;
	int_min = -2147483648;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		d = s[i] - '0';
		if (acc > (int_max - d) / 10)
			return (-1);
		acc = acc * 10 + d;
		i++;
	}
	acc = acc * sign;
	if (acc > int_max || acc < int_min)
		return (-1);
	if (contains(*head, (int)acc))
		return (-1);
	save_head(head, (int)acc);
	return (i);
}

int	parsing(t_node **head, const char *str)
{
	int		i;
	int		sign;
	int		possible;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (!str[i])
			break ;
		possible = parse_sign(str, i, &sign);
		if (possible < 0)
			return (0);
		i = possible;
		possible = parse_digit(head, str, i, sign);
		if (possible < 0)
			return (0);
		i = possible;
	}
	return (1);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}
