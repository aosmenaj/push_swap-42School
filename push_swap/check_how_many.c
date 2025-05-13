/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_how_many.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:26:51 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/22 11:13:50 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_how_many(t_node **stack)
{
	int		i;
	t_node	*temp;

	temp = *stack;
	i = 0;
	while (*stack)
	{
		*stack = (*stack)->next;
		i++;
	}
	*stack = temp;
	return (i);
}
