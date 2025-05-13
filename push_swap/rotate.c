/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:48:13 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/21 17:49:08 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate(t_node **stack)
{
	t_node	*t1;

	t1 = find_last_node(*stack);
	t1->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	t1->next->previous = t1;
	t1->next->next = NULL;
}

void	ra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a + 1))
		return ;
	rotate(stack_a);
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b + 1))
		return ;
	rotate(stack_b);
	write(1, "rb\n", 3);
	return ;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !(*stack_a + 1) || !*stack_b || !(*stack_b + 1))
		return ;
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return ;
}
