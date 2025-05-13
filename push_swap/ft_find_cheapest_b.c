/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_cheapest_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:13:06 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/21 21:02:09 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	determine_median(t_node **stack_b, int median_a, int median_b)
{
	if ((*stack_b)->index <= median_b)
		(*stack_b)->above_median = 1;
	else
		(*stack_b)->above_median = 0;
	if ((*stack_b)->target->index <= median_a)
		(*stack_b)->target->above_median = 1;
	else
		(*stack_b)->target->above_median = 0;
}

static	void	determine_push_cost(t_node *stack, int a_size, int b_size)
{
	int	ib;
	int	ia;

	ib = stack->index;
	ia = stack->target->index;
	if (stack->above_median && stack->target->above_median)
	{
		if (ib < ia)
			stack->push_cost = ia;
		else
			stack->push_cost = ib;
	}
	if (stack->above_median && !stack->target->above_median)
		stack->push_cost = ib + (a_size - ia);
	if (!stack->above_median && stack->target->above_median)
		stack->push_cost = ia + (b_size - ib);
	if (!stack->above_median && !stack->target->above_median)
	{
		if ((b_size - ib) < (a_size - ia))
			stack->push_cost = (a_size - ia);
		else
			stack->push_cost = (b_size - ib);
	}
}

static	t_node	*determine_cheapest(t_node **stack, t_node *cheapest)
{
	if ((*stack)->previous == NULL)
	{
		(*stack)->cheapest = 1;
		cheapest = *stack;
	}
	else
	{
		if ((*stack)->push_cost < cheapest->push_cost)
		{
			(*stack)->cheapest = 1;
			cheapest->cheapest = 0;
			cheapest = *stack;
		}
	}
	return (cheapest);
}

t_node	*ft_find_cheapest_b(t_node **stack_b, int i)
{
	int		median_a;
	int		median_b;
	t_node	*temp;
	t_node	*cheapest;

	temp = *stack_b;
	cheapest = NULL;
	median_a = i / 2;
	median_b = check_how_many(stack_b) / 2;
	while (*stack_b != NULL)
	{
		determine_median(stack_b, median_a, median_b);
		determine_push_cost(*stack_b, i, check_how_many(stack_b));
		if ((*stack_b)->push_cost == 0 || (*stack_b)->push_cost == 1)
		{
			cheapest = *stack_b;
			break ;
		}
		cheapest = determine_cheapest(stack_b, cheapest);
		*stack_b = (*stack_b)->next;
	}
	*stack_b = temp;
	return (cheapest);
}
