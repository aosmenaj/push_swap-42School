/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:20:58 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/02 17:16:25 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort_type(t_node **stack_a, t_node **stack_b, int i)
{
	if (i == 1)
		return ;
	if (i < 3 && ((*stack_a)->content > (*stack_a)->next->content))
		sa(stack_a);
	else if (i == 3)
		sort_three(stack_a);
	else if (i > 3)
		full_sort(stack_a, stack_b, i);
	ft_free_stack(stack_a);
	return ;
}
