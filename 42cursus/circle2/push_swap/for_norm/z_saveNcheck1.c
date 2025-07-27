/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_saveNcheck1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:18:40 by si-park           #+#    #+#             */
/*   Updated: 2025/07/27 19:23:15 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	save_head(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*cur;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->data = value;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	cur = *head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
}

int	contains(t_node *head, int v)
{
	while (head)
	{
		if (head->data == v)
			return (1);
		head = head->next;
	}
	return (0);
}

void	free_list(t_node **head)
{
	t_node	*cur;
	t_node	*nn;

	cur = *head;
	while (cur)
	{
		nn = cur->next;
		free(cur);
		cur = nn;
	}
	*head = NULL;
}

int	list_size(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

int	list_max(t_node *head)
{
	int	max;

	max = head->data;
	while (head)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	return (max);
}
