/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:57:38 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/01/31 15:45:50 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_node	*ft_find_min_nb(t_node *stack)
{
	t_node	*min_nb;
	t_node	*temp;
	int		index;

	index = 0;
	temp = stack;
	min_nb = stack;
	while (stack)
	{
		stack->index = index;
		if (stack->content < min_nb->content)
			min_nb = stack;
		stack = stack->next;
		index++;
	}
	stack = temp;
	return (min_nb);
}

void	ft_last_check(t_node **stack_a, int i)
{
	t_node	*temp;
	int		ia;
	int		am;

	temp = *stack_a;
	*stack_a = ft_find_min_nb(*stack_a);
	ia = (*stack_a)->index;
	am = i - ia;
	if (ia <= (i / 2))
	{
		*stack_a = temp;
		while (ia-- > 0)
			ra(stack_a);
	}
	else
	{
		*stack_a = temp;
		while (am-- > 0)
			rra(stack_a);
	}
	return ;
}
