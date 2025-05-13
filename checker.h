/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:17:11 by aosmenaj          #+#    #+#             */
/*   Updated: 2025/05/13 11:40:06 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct node
{
	int				content;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct node		*target;
	struct node		*next;
	struct node		*previous;
}	t_node;

int		ft_check_if_valid_bonus(char **argv, int argc);
void	read_moves(t_node **stack_a, t_node **stack_b);
void	pute_node_bonus(t_node **stack_a, t_node **stack_b,
			char **argv, int argc);
int		myatoi_bonus(char const *s, int *err, int *pos);
void	ft_exit_bonus(t_node **stack_a, t_node **stack_b);
void	ss_bonus(t_node **a, t_node **b);
void	sb_bonus(t_node **b);
void	sa_bonus(t_node **a);
void	ra_bonus(t_node **stack_a);
void	rb_bonus(t_node **stack_b);
void	rr_bonus(t_node **stack_a, t_node **stack_b);
void	rra_bonus(t_node **stack_a);
void	rrb_bonus(t_node **stack_b);
void	rrr_bonus(t_node **stack_a, t_node **stack_b);
void	pb_bonus(t_node **stack_a, t_node **stack_b);
void	pa_bonus(t_node **stack_b, t_node **stack_a);

#endif
