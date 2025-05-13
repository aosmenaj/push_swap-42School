/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:48:13 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/23 17:40:32 by aosmenaj         ###   ########.fr       */
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

void	ra_bonus(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a + 1))
		return ;
	rotate(stack_a);
	return ;
}

void	rb_bonus(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b + 1))
		return ;
	rotate(stack_b);
	return ;
}

void	rr_bonus(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !(*stack_a + 1) || !*stack_b || !(*stack_b + 1))
		return ;
	rotate(stack_a);
	rotate(stack_b);
	return ;
}
