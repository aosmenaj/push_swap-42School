/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:14:44 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/22 11:15:26 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_node	*ft_find_min_nb(t_node *stack)
{
	t_node	*min_nb;
	t_node	*temp;

	temp = stack;
	min_nb = stack;
	while (stack)
	{
		if (stack->content < min_nb->content)
			min_nb = stack;
		stack = stack->next;
	}
	stack = temp;
	return (min_nb);
}

static	void	ft_calculate(t_node **stack_a, t_node **stack_b)
{
	int		index;
	t_node	*temp;

	temp = *stack_b;
	index = 0;
	while (*stack_b != NULL)
	{
		if ((*stack_b) && (*stack_b)->target)
			(*stack_b)->target = NULL;
		ft_find_target_in_a(stack_a, stack_b);
		(*stack_b)->index = index++;
		if (!((*stack_b)->target))
			(*stack_b)->target = ft_find_min_nb(*stack_a);
		*stack_b = (*stack_b)->next;
	}
	*stack_b = temp;
	return ;
}

int	ft_back_to_a(t_node **stack_a, t_node **stack_b, int i)
{
	int		b_size;
	t_node	*cheapest;

	b_size = check_how_many(stack_b);
	while (b_size > 0)
	{
		ft_calculate(stack_a, stack_b);
		cheapest = ft_find_cheapest_b(stack_b, i);
		ft_push_in_a(stack_a, stack_b, i, cheapest);
		b_size--;
		i++;
	}
	return (i);
}
