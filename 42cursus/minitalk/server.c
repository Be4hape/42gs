/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:30:37 by si-park           #+#    #+#             */
/*   Updated: 2025/07/16 12:40:25 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	handler(int sig)
{
	static unsigned char	str;
	static unsigned int		i;
	static int				init;

	if (!init)
	{
		str = 0;
		i = 0;
		init = 1;
	}
	if (sig == SIGUSR1)
		str |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(str, 1);
		str = 0;
		i = 0;
	}
}

int	main(void)
{
	write(1, "pid : ", 6);
	ft_putnbr_fd(getpid(), 1);
	write(1, ", waiting\n", 10);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
