/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:00:20 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/01/26 13:35:14 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_max_nb(t_node **stack)
{
	t_node	*max_nb;
	t_node	*temp;

	temp = *stack;
	max_nb = *stack;
	while (*stack)
	{
		if ((*stack)->content > max_nb->content)
			max_nb = *stack;
		*stack = (*stack)->next;
	}
	*stack = temp;
	return (max_nb);
}
