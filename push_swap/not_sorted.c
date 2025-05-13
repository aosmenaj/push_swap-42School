/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:49:35 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/01/31 15:47:15 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_sorted(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	if ((*stack_a)->next == NULL)
		return (0);
	while (*stack_a)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			*stack_a = temp;
			return (1);
		}
		*stack_a = (*stack_a)->next;
		if ((*stack_a)->next == NULL)
		{
			*stack_a = temp;
			return (0);
		}
	}
	*stack_a = temp;
	return (0);
}
