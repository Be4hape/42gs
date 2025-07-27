/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:15:00 by si-park           #+#    #+#             */
/*   Updated: 2025/07/27 17:42:48 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	swap_sa(t_node **a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	swap_sb(t_node **b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	swap_ss(t_node **a, t_node **b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}
