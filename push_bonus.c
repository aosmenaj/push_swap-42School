/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push _bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:48:31 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/23 17:34:40 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	push(t_node **stack_1, t_node **stack_2)
{
	t_node	*nodeb;

	nodeb = (*stack_1);
	if (*stack_2)
	{
		(*stack_2)->previous = nodeb;
		*stack_1 = (*stack_1)->next;
		nodeb->next = *stack_2;
		*stack_2 = (*stack_2)->previous;
		if ((*stack_1) != NULL)
			(*stack_1)->previous = NULL;
	}
	else
	{
		(*stack_2) = nodeb;
		*stack_1 = (*stack_1)->next;
		if ((*stack_1) != NULL)
			(*stack_1)->previous = NULL;
		(*stack_2)->next = NULL;
		(*stack_2)->previous = NULL;
	}
	return ;
}

void	pb_bonus(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a)
		return ;
	push(stack_a, stack_b);
	return ;
}

void	pa_bonus(t_node **stack_b, t_node **stack_a)
{
	if (!*stack_b)
		return ;
	push(stack_b, stack_a);
	return ;
}
