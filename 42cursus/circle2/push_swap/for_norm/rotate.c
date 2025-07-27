/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:16:07 by si-park           #+#    #+#             */
/*   Updated: 2025/07/27 17:42:18 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*cur;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	*head = first->next;
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = first;
	first->next = NULL;
}

void	rotate_ra(t_node **a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rotate_rb(t_node **b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rotate_rr(t_node **a, t_node **b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}
