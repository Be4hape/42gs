/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:06:14 by si-park           #+#    #+#             */
/*   Updated: 2025/07/28 14:31:23 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int is_sorting(t_node *head){
	while (head && head -> next){
		if ((head -> data) > (head -> next -> data))
			return (0);
		head = head -> next;
	}
	return (1);
}

void	rdx_sorting(t_node **a, t_node **b, int max_data, int max_bit)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = list_size(*a);
	max_data = list_max(*a);
	max_bit = 0;
	while ((max_data >> max_bit) != 0)
		max_bit++;
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->data >> i) & 1) == 0)
				push_pb(a, b);
			else
				rotate_ra(a);
			j++;
		}
		while (*b)
			push_pa(a, b);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_node	*head_a;
	t_node	*head_b;
	int		i;

	head_a = NULL;
	head_b = NULL;
	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!parsing(&head_a, av[i]))
		{
			print_error();
			free_list(&head_a);
			return (1);
		}
		i++;
	}
	if(is_sorting(head_a))
		return (0);
	rdx_sorting(&head_a, &head_b, 0, 0);
	free_list(&head_a);
	return (0);
}
