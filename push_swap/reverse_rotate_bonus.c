/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:48:17 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/23 17:40:15 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	t_node	*find_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

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

void	rra_bonus(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a + 1))
		return ;
	reverse_rotate(stack_a);
	return ;
}

void	rrb_bonus(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b + 1))
		return ;
	reverse_rotate(stack_b);
	return ;
}

void	rrr_bonus(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !(*stack_a + 1) || !*stack_b || !(*stack_b + 1))
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return ;
}
