/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_cheapest_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:11:07 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/21 20:55:06 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	determine_median(t_node **stack_a, int median_a, int median_b)
{
	if ((*stack_a)->index <= median_a)
		(*stack_a)->above_median = 1;
	else
		(*stack_a)->above_median = 0;
	if ((*stack_a)->target->index <= median_b)
		(*stack_a)->target->above_median = 1;
	else
		(*stack_a)->target->above_median = 0;
}

static	void	determine_push_cost(t_node *stack, int a_size, int b_size)
{
	int	ia;
	int	ib;

	ia = stack->index;
	ib = stack->target->index;
	if (stack->above_median && stack->target->above_median)
	{
		if (ia < ib)
			stack->push_cost = ib;
		else
			stack->push_cost = ia;
	}
	if (stack->above_median && !stack->target->above_median)
		stack->push_cost = ia + (b_size - ib);
	if (!stack->above_median && stack->target->above_median)
		stack->push_cost = ib + (a_size - ia);
	if (!stack->above_median && !stack->target->above_median)
	{
		if ((a_size - ia) < (b_size - ib))
			stack->push_cost = (b_size - ib);
		else
			stack->push_cost = (a_size - ia);
	}
}

static	t_node	*determine_cheapest(t_node **stack_a, t_node *cheapest)
{
	if ((*stack_a)->previous == NULL)
	{
		(*stack_a)->cheapest = 1;
		cheapest = *stack_a;
	}
	else
	{
		if ((*stack_a)->push_cost < cheapest->push_cost)
		{
			(*stack_a)->cheapest = 1;
			cheapest->cheapest = 0;
			cheapest = *stack_a;
		}
	}
	return (cheapest);
}

t_node	*ft_find_cheapest_a(t_node **stack_a, t_node **stack_b, int i)
{
	int		median_a;
	int		median_b;
	t_node	*temp;
	t_node	*cheapest;

	temp = *stack_a;
	cheapest = NULL;
	median_a = i / 2;
	median_b = check_how_many(stack_b) / 2;
	while (*stack_a != NULL)
	{
		determine_median(stack_a, median_a, median_b);
		determine_push_cost(*stack_a, i, check_how_many(stack_b));
		if ((*stack_a)->push_cost == 0 || (*stack_a)->push_cost == 1)
		{
			cheapest = *stack_a;
			break ;
		}
		cheapest = determine_cheapest(stack_a, cheapest);
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp;
	return (cheapest);
}
