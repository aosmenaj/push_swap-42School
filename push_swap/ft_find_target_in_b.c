/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_target_in_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:06:56 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/01/31 20:21:09 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target_in_b(t_node **stack_a, t_node **stack_b)
{
	int		index;
	t_node	*temp;

	temp = *stack_b;
	index = 0;
	while ((*stack_a)->target == NULL && (*stack_b) != NULL)
	{
		if ((*stack_a)->content > (*stack_b)->content)
			(*stack_a)->target = (*stack_b);
		(*stack_b)->index = index++;
		*stack_b = (*stack_b)->next;
	}
	while ((*stack_b) != NULL)
	{
		if ((*stack_b)->content < (*stack_a)->content
			&& (*stack_b)->content > (*stack_a)->target->content)
			(*stack_a)->target = (*stack_b);
		(*stack_b)->index = index++;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = temp;
}
