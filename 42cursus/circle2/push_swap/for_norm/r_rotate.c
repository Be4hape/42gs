/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:28:34 by si-park           #+#    #+#             */
/*   Updated: 2025/07/27 17:41:31 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	reverse_rotate(t_node **head)
{
	t_node	*prev;
	t_node	*cur;

	prev = NULL;
	cur = *head;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	cur->next = *head;
	*head = cur;
}

void	rotate_rra(t_node **a)
{
	write(1, "rra\n", 4);
	reverse_rotate(a);
}

void	rotate_rrb(t_node **b)
{
	write(1, "rrb\n", 4);
	reverse_rotate(b);
}

void	rotate_rrr(t_node **a, t_node **b)
{
	write(1, "rrr\n", 4);
	reverse_rotate(a);
	reverse_rotate(b);
}
