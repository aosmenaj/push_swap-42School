/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:58:15 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/22 11:06:57 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	initial_push(t_node **stack_a, t_node **stack_b, int i)
{
	if (i == 4)
	{
		pb(stack_a, stack_b);
		i--;
	}
	else if (i > 4)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		i -= 2;
	}
	return (i);
}

static	void	ft_calculate1(t_node **stack_a, t_node **stack_b)
{
	int		index;
	t_node	*temp;

	temp = *stack_a;
	index = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->target)
			(*stack_a)->target = NULL;
		ft_find_target_in_b(stack_a, stack_b);
		(*stack_a)->index = index++;
		if (!((*stack_a)->target))
			(*stack_a)->target = ft_find_max_nb(stack_b);
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp;
	return ;
}

void	full_sort(t_node **stack_a, t_node **stack_b, int i)
{
	t_node	*cheapest;

	i = initial_push(stack_a, stack_b, i);
	while (i > 3)
	{
		ft_calculate1(stack_a, stack_b);
		cheapest = ft_find_cheapest_a(stack_a, stack_b, i);
		ft_push_in_b(stack_a, stack_b, i, cheapest);
		i--;
	}
	sort_three(stack_a);
	i = ft_back_to_a(stack_a, stack_b, i);
	if (not_sorted(stack_a))
		ft_last_check(stack_a, i);
	return ;
}
