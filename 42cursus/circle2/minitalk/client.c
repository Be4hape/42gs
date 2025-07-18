/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:30:44 by si-park           #+#    #+#             */
/*   Updated: 2025/07/16 11:14:14 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	send_char(pid_t server_pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*string;
	pid_t	server_pid;

	if (argc == 3 && argv[2])
	{
		string = argv[2];
		server_pid = (pid_t)ft_atoi(argv[1]);
		i = 0;
		while (string[i])
		{
			send_char(server_pid, (unsigned char)string[i]);
			i++;
		}
	}
	return (0);
}
