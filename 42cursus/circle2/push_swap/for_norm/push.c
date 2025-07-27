/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:15:40 by si-park           #+#    #+#             */
/*   Updated: 2025/07/27 17:41:01 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	push(t_node **a, t_node **b)
{
	t_node	*n_a;
	t_node	*n_b;

	n_a = *a;
	*a = n_a->next;
	n_b = *b;
	*b = n_a;
	n_a->next = n_b;
}

void	push_pa(t_node **a, t_node **b)
{
	write(1, "pa\n", 3);
	if (!*b)
		return ;
	push(b, a);
}

void	push_pb(t_node **a, t_node **b)
{
	write(1, "pb\n", 3);
	if (!*a)
		return ;
	push(a, b);
}
