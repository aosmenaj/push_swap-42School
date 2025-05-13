/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_in_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:12:59 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/22 11:14:59 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push_case_1(int ia, int ib, t_node **stack_a, t_node **stack_b)
{
	while (ia != 0 && ib != 0)
	{
		rr(stack_a, stack_b);
		ia--;
		ib--;
	}
	if (ia != 0)
	{
		while (ia != 0)
		{
			ra(stack_a);
			ia--;
		}
	}
	else if (ib != 0)
	{
		while (ib != 0)
		{
			rb(stack_b);
			ib--;
		}
	}
	pb(stack_a, stack_b);
}

static	void	push_case_2(int ia, int ib, t_node **stack_a, t_node **stack_b)
{
	int	mb;

	mb = check_how_many(stack_b) - ib;
	while (ia != 0)
	{
		ra(stack_a);
		ia--;
	}
	while (mb != 0)
	{
		rrb(stack_b);
		mb--;
	}
	pb(stack_a, stack_b);
}

static	void	push_case_3(int ia, int ib, t_node **stack_a, t_node **stack_b)
{
	int	ma;

	ma = check_how_many(stack_a) - ia;
	while (ib != 0)
	{
		rb(stack_b);
		ib--;
	}
	while (ma != 0)
	{
		rra(stack_a);
		ma--;
	}
	pb(stack_a, stack_b);
}

static	void	push_case_4(int ma, int mb, t_node **stack_a, t_node **stack_b)
{
	while (ma != 0 && mb != 0)
	{
		rrr(stack_a, stack_b);
		ma--;
		mb--;
	}
	if (ma != 0)
	{
		while (ma != 0)
		{
			rra(stack_a);
			ma--;
		}
	}
	else if (mb != 0)
	{
		while (mb != 0)
		{
			rrb(stack_b);
			mb--;
		}
	}
	pb(stack_a, stack_b);
}

void	ft_push_in_b(t_node **stack_a, t_node **stack_b, int i,
			t_node	*cheapest)
{
	int		ia;
	int		ib;
	int		b_size;
	t_node	*temp;

	temp = cheapest;
	b_size = check_how_many(stack_b);
	ia = temp->index;
	ib = temp->target->index;
	if (temp->above_median && temp->target->above_median)
		push_case_1(ia, ib, stack_a, stack_b);
	else if (temp->above_median && !temp->target->above_median)
		push_case_2(ia, ib, stack_a, stack_b);
	else if (!temp->above_median && temp->target->above_median)
		push_case_3(ia, ib, stack_a, stack_b);
	else if (!temp->above_median && !temp->target->above_median)
		push_case_4((i - ia), (b_size - ib), stack_a, stack_b);
}
