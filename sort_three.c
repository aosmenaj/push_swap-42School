/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:11:35 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/01/30 17:38:48 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int	x;
	int	y;
	int	z;

	x = (*stack)->content;
	y = (*stack)->next->content;
	z = (*stack)->next->next->content;
	if (x > y && x < z)
		sa(stack);
	else if (x > y && x > z && y > z)
	{
		ra(stack);
		sa(stack);
	}
	else if (x < y && x > z)
		rra(stack);
	else if (x < y && x < z && y > z)
	{
		rra(stack);
		sa(stack);
	}
	else if (x > y && x > z && y < z)
		ra(stack);
	return ;
}
