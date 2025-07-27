/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:06:36 by si-park           #+#    #+#             */
/*   Updated: 2025/07/27 17:37:10 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

void	swap_sa(t_node **a);
void	swap_sb(t_node **b);
void	swap_ss(t_node **a, t_node **b);
void	push_pa(t_node **a, t_node **b);
void	push_pb(t_node **a, t_node **b);
void	rotate_ra(t_node **a);
void	rotate_rb(t_node **b);
void	rotate_rr(t_node **a, t_node **b);
void	rotate_rra(t_node **a);
void	rotate_rrb(t_node **b);
void	rotate_rrr(t_node **a, t_node **b);

int		parsing(t_node **head, const char *str);
int		list_size(t_node *head);
int		list_max(t_node *head);

void	save_head(t_node **head, int value);
void	print_error(void);
void	free_list(t_node **head);
int		contains(t_node *head, int v);

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

#endif
