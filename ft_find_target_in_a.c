/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_target_in_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:10:39 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/06 15:15:44 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target_in_a(t_node **stack_a, t_node **stack_b)
{
	int		index;
	t_node	*temp;

	temp = *stack_a;
	index = 0;
	while ((*stack_b)->target == NULL && (*stack_a) != NULL)
	{
		if ((*stack_b)->content < (*stack_a)->content)
			(*stack_b)->target = *stack_a;
		(*stack_a)->index = index++;
		*stack_a = (*stack_a)->next;
	}
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->content < (*stack_b)->target->content
			&& (*stack_a)->content > (*stack_b)->content)
			(*stack_b)->target = *stack_a;
		(*stack_a)->index = index++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp;
}
