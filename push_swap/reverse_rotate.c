/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:48:17 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/22 17:00:33 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	reverse_rotate(t_node **stack)
{
	t_node	*t2;

	t2 = find_last_node(*stack);
	t2->next = *stack;
	(*stack)->previous = t2;
	t2->previous->next = NULL;
	t2->previous = NULL;
	(*stack) = t2;
}

void	rra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a + 1))
		return ;
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b + 1))
		return ;
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !(*stack_a + 1) || !*stack_b || !(*stack_b + 1))
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	return ;
}
