/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:25:00 by si-park           #+#    #+#             */
/*   Updated: 2024/11/09 22:48:13 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (*s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
		return ;
	}
	write(fd, "\n", 1);
}
